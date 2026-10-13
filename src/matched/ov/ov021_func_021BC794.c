/*
 * function: FIELD_PLACE_NAME_CreateClactUnit
 * address:  0x021BC794
 * packet:   pkt_ov021_021BC794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetHeapId  0x021BD090  thumb  ov021
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 */

typedef struct {
    char pad[0x34];
    void *f34;
} Obj;

typedef unsigned short u16;
extern u16 FIELD_PLACE_NAME_GetHeapId(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);

void FIELD_PLACE_NAME_CreateClactUnit(Obj *p)
{
    p->f34 = CLACT_CreateUnit(0x1E, 1, FIELD_PLACE_NAME_GetHeapId((unsigned char *)p));
    func_0204B22C(p->f34, 1);
}
