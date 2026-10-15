/*
 * function: ISS_CITY_SYS_FreeUnits
 * address:  0x0202ABD0
 * packet:   pkt_0202AB7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ISS_CITY_UNIT_Delete  0x0202AF28  thumb
 *   GFL_HEAP_Free   0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8 pad[0x14];
    void **arr;
    u8 count;
};

extern void ISS_CITY_UNIT_Delete(void *item);
extern u32 GFL_HEAP_Free(void *p);

void ISS_CITY_SYS_FreeUnits(struct Obj *obj)
{
    int i;
    int count = obj->count;

    for (i = 0; i < count; i++) {
        ISS_CITY_UNIT_Delete(obj->arr[i]);
    }
    GFL_HEAP_Free(obj->arr);
    obj->arr = 0;
}
