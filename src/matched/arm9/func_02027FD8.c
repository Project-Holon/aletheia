/*
 * function: APP_TASKMENU_RES_Delete
 * address:  0x02027FD8
 * packet:   pkt_02027A04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct TaskMenuState {
    u8 pad[8];
    void *child;
};

extern u32 GFL_HEAP_Free(void *p);

u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s)
{
    GFL_HEAP_Free(s->child);
    return GFL_HEAP_Free(s);
}
