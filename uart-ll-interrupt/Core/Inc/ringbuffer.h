#ifndef __RINGBUFFER_H
#define __RINGBUFFER_H

#include <string.h>
#include <stdint.h>

typedef struct ringbuffer {
    uint8_t *buff;
    size_t size;
    size_t head;
    size_t tail;
    size_t count;
} ringbuffer_t;

uint8_t rb_init(ringbuffer_t *rb, uint8_t *buff, size_t size);
size_t rb_write(ringbuffer_t *rb, uint8_t *data, size_t len);
size_t rb_read(ringbuffer_t *rb, uint8_t *data, size_t len);
size_t rb_get_free(ringbuffer_t *rb);
uint8_t rb_is_empty(ringbuffer_t *rb);
uint8_t rb_is_full(ringbuffer_t *rb);
uint8_t rb_reset(ringbuffer_t *rb);
#endif
