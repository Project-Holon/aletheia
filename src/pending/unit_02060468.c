/*
 * function: func_02060468
 * address:  0x02060468
 * packet:   pkt_02060468
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * unit:     yes
 *
 * functions:
 *   func_02060468  0x02060468  arm
 *   func_02060480  0x02060480  arm
 *   func_020604AC  0x020604AC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RingBuffer {
    u32 head;
    u32 tail;
    u16 count;
    u16 size;
};

void func_02060468(struct RingBuffer *buf, u16 size)
{
    buf->head = 0;
    buf->tail = 0;
    buf->count = 0;
    buf->size = size;
}

void func_02060480(struct RingBuffer *buf, u8 *data)
{
    u16 size = buf->size;
    u8 *ptr = data + size;
    u32 head = (u32)data;
    *(u32 *)(ptr + 4) = 0;
    *(u32 *)ptr = 0;
    buf->head = head;
    buf->tail = head;
    buf->count++;
}

void func_020604AC(struct RingBuffer *buf, void *data)
{
    if (buf->head == 0) {
        func_02060480(buf, (u8 *)data);
    } else {
        return;
    }
}
