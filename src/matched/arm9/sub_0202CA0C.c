/*
 * function: BGWINFRM_Delete
 * address:  0x0202CA0C
 * packet:   pkt_0202C860
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Elem {
    void *ptr;
    u8 pad[12];
};

struct WinMgr {
    struct Elem *arr;
    u16 count;
};

extern u32 GFL_HEAP_Free(void *p);

void BGWINFRM_Delete(struct WinMgr *obj)
{
    u32 i;

    for (i = 0; i < obj->count; i++) {
        if (obj->arr[i].ptr != 0) {
            GFL_HEAP_Free(obj->arr[i].ptr);
        }
    }
    GFL_HEAP_Free(obj->arr);
    GFL_HEAP_Free(obj);
}
