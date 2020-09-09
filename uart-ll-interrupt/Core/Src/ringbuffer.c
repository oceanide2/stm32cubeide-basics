#include "ringbuffer.h"

uint8_t rb_init(ringbuffer_t *rb, uint8_t *buff, size_t size)
{
    if (rb == NULL || buff == NULL || size == 0) {
        return 0;
    }

    memset(rb, 0x00, sizeof(*rb));

    rb->buff = buff;
    rb->size = size;

    return 1;
}

size_t rb_get_free(ringbuffer_t *rb)
{
    return (rb->size - 1) - rb->count;
}

uint8_t rb_is_empty(ringbuffer_t *rb)
{
    return rb->count == 0;
}

uint8_t rb_is_full(ringbuffer_t *rb)
{
    return (rb->size - 1) == rb->count;
}

uint8_t rb_reset(ringbuffer_t *rb)
{
    if (rb == NULL) {
        return 0;
    }

    rb->head = 0;
    rb->tail = 0;

    return 1;
}

size_t rb_write(ringbuffer_t *rb, uint8_t *data, size_t len)
{
    size_t tocopy;
    size_t free = rb_get_free(rb);

    if (free == 0) {
        return 0;
    }

    if (len > free) {
        len = free;
    }

    if (rb->head + len > rb->size) {
        tocopy = rb->size - rb->head;
        memcpy(&rb->buff[rb->head], data, tocopy);
        memcpy(&rb->buff[0], &data[tocopy], len - tocopy);
        rb->head = len - tocopy;
    } else {
        memcpy(&rb->buff[rb->head], data, len);
        rb->head += len;
    }

    if (rb->head >= rb->size) {
        rb->head = 0;
    }
    rb->count += len;

    return len;
}

size_t rb_read(ringbuffer_t *rb, uint8_t *data, size_t len)
{
    size_t tocopy;

    if (rb_is_empty(rb)) {
        return 0;
    }

    if (len > rb->count) {
        len = rb->count;
    }

    if (rb->tail + len > rb->size) {
        tocopy = rb->size - rb->tail;
        memcpy(data, &rb->buff[rb->tail], tocopy);
        memcpy(&data[tocopy], &rb->buff[0], len - tocopy);
        rb->tail = len - tocopy;
    } else {
        memcpy(data, &rb->buff[rb->tail], len);
        rb->tail += len;
    }

    if (rb->tail >= rb->size) {
        rb->tail =  0;
    }

    rb->count -= len;

    return len;
}
