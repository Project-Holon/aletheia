/*
 * function: VMAN_Delete
 * address:  0x020345DC
 * packet:   pkt_02034520
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   AREAMAN_Delete  0x02033C9C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */

struct Struct020345DC {
    void *ptr;
};

extern unsigned int AREAMAN_Delete(void *a);
typedef unsigned int   u32;
extern u32 GFL_HEAP_Free(void *p);

void VMAN_Delete(struct Struct020345DC *obj)
{
    AREAMAN_Delete(obj->ptr);
    GFL_HEAP_Free(obj);
}
