/*
 * function: GFL_NET_RING_BUFF_Write
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
 *   GFL_NET_RING_BUFF_GetWritableSize  0x02036640  arm
 *   GFL_NET_SYSTEM_SetError  0x02039548  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_RING_BUFF_WrapPos  0x02036624  arm
 *   file_020A79A4  0x020A79A4  data
 *   str_020A79B4   0x020A79B4  data
 *
 * net_ring_buff.c's write: refuse (GFL_NET_SYSTEM_SetError) unless the free space
 * (GFL_NET_RING_BUFF_GetWritableSize) exceeds len, then copy len bytes in at the +0xE write
 * cursor modulo the capacity (GFL_NET_RING_BUFF_WrapPos), asserting src != NULL at line
 * 0x44 each byte, and store the wrapped cursor back.  The write cursor is
 * declared volatile: the loop bound re-reads it every pass and the first
 * read happens twice, exactly as the image does (the same re-read shape the
 * matched GFL_NET_RING_BUFF_GetDataSize spells with volatile casts).
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

extern int GFL_NET_RING_BUFF_GetWritableSize(char *p);
extern void GFL_NET_SYSTEM_SetError(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int GFL_NET_RING_BUFF_WrapPos(void *p, int v);
extern const char file_020A79A4[];
extern const char str_020A79B4[];

void GFL_NET_RING_BUFF_Write(NetRingBuff *r, const u8 *src, int len)
{
    int i;
    int k;

    if (GFL_NET_RING_BUFF_GetWritableSize((char *)r) <= len) {
        GFL_NET_SYSTEM_SetError();
        return;
    }
    k = 0;
    for (i = r->tail; i < r->tail + len; i++) {
        if (src == 0) {
            func_02034714(file_020A79A4, 0x44, str_020A79B4);
        }
        r->buf[GFL_NET_RING_BUFF_WrapPos(r, i)] = src[k];
        k++;
    }
    r->tail = (short)GFL_NET_RING_BUFF_WrapPos(r, i);
}
