/*
 * function: func_021BCFE0
 * address:  0x021BCFE0
 * packet:   pkt_ov021_021BCFE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD090  0x021BD090  thumb  ov021
 */

typedef struct {
    char pad[8];
    void *f8;
} Obj;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_021BD090(u8 *p);
typedef unsigned int   u32;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);

void func_021BCFE0(Obj *p)
{
    p->f8 = func_0201EC64(func_021BD090((u8 *)p));
}
