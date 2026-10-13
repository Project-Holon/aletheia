/*
 * function: func_02175548
 * address:  0x02175548
 * packet:   pkt_ov011_02175548
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008530  0x02008530  thumb
 *   func_02008550  0x02008550  thumb
 *   gIntrudeCommObjCodesMale   0x02176A90  data  ov011  a2
 *   gIntrudeCommObjCodesFemale   0x02176A98  data  ov011  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u16 gIntrudeCommObjCodesMale[];
extern u16 gIntrudeCommObjCodesFemale[];

void func_02175548(u32 a, u16 *p1, u8 *p2, u8 *p3)
{
    u32 x;
    u32 i;
    int r;

    x = func_02008530((const struct Sub0200852CObj *)a);
    r = func_02008550((const struct Sub0200852CObj *)a);
    i = ((x >> 16) + (u16)x) & 3;
    if (r == 0) {
        *p1 = gIntrudeCommObjCodesMale[i];
        *p2 = 3;
        *p3 = 0;
    } else {
        *p1 = gIntrudeCommObjCodesFemale[i];
        *p2 = 4;
        *p3 = 1;
    }
}
