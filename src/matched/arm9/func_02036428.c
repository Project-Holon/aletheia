/*
 * function: func_02036428
 * address:  0x02036428
 * packet:   pkt_02036428
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02036640  0x02036640  arm
 *   func_02039548  0x02039548  arm
 *   func_02034714  0x02034714  arm
 *   func_02036624  0x02036624  arm
 *   file_020A79A4  0x020A79A4  data
 *   str_020A79B4   0x020A79B4  data
 *
 * net_ring_buff.c's write: refuse (func_02039548) unless the free space
 * (func_02036640) exceeds len, then copy len bytes in at the +0xE write
 * cursor modulo the capacity (func_02036624), asserting src != NULL at line
 * 0x44 each byte, and store the wrapped cursor back.  The write cursor is
 * declared volatile: the loop bound re-reads it every pass and the first
 * read happens twice, exactly as the image does (the same re-read shape the
 * matched func_020365E8 spells with volatile casts).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8   *buf;
    int   size;
    u32   pad8;
    short head;
    volatile short tail;
} NetRingBuff;

extern int  func_02036640(NetRingBuff *r);
extern void func_02039548(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_02036624(void *p, int v);
extern const char file_020A79A4[];
extern const char str_020A79B4[];

void func_02036428(NetRingBuff *r, const u8 *src, int len)
{
    int i;
    int k;

    if (func_02036640(r) <= len) {
        func_02039548();
        return;
    }
    k = 0;
    for (i = r->tail; i < r->tail + len; i++) {
        if (src == 0) {
            func_02034714(file_020A79A4, 0x44, str_020A79B4);
        }
        r->buf[func_02036624(r, i)] = src[k];
        k++;
    }
    r->tail = (short)func_02036624(r, i);
}
