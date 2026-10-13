/*
 * function: FIELD_PLACE_NAME_ClearWindow
 * address:  0x021BC720
 * packet:   pkt_ov021_021BC720
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm  arm9
 */

typedef struct {
    char pad[0x24];
    void *f24;
} Obj;

typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);

void FIELD_PLACE_NAME_ClearWindow(Obj *p)
{
    BMP_Clear(func_02045770(p->f24), 3);
}
