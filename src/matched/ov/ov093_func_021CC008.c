/*
 * function: func_021CC008
 * address:  0x021CC008
 * packet:   pkt_ov093_021CC008
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The switch stores into w+6 in every arm (as func_021CC2C0 does), which
 * lays the arms out as the original has them; the default arm calls
 * func_021D805C again. s is narrow: as u32 (or a pointer, as the sibling
 * handlers func_021CC2C0/CC178/CC214 declare it) its `ldr r0,[sp]` reload
 * is hoisted above `strb r7,[r4,#4]`; u16 and u8 both keep it below.
 * Nothing in the image fixes the width; u16 chosen. The function sits in
 * the handler table at 0x021EFE28.
 *
 * symbols:
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C84E0  0x021C84E0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D5B68(void *p);
extern u8 func_021D5440(u8 *p);
extern void *func_021C88A4(void *a, int k, int b);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
extern void func_021C84E0(unsigned char *p, unsigned int v);

int func_021CC008(u8 *p, u8 *q, u16 s)
{
    int id;
    u8 *w;
    u32 r;
    if (func_021D5B68(q)) {
        id = func_021D5440(q);
        w = func_021C88A4(p, 0x2c, id);
        w[4] = id;
        r = func_021D805C((void *)s, 0x3a);
        switch (r) {
        case 0xff:
            *(u16 *)(w + 6) = func_021D59B4(q, 0xe);
            break;
        case 0xfe:
            *(u16 *)(w + 6) = func_021D7B74(q, 2);
            break;
        case 0xfd:
            *(u16 *)(w + 6) = func_021D7B74(q, 4);
            break;
        default:
            *(u16 *)(w + 6) = func_021D805C((void *)s, 0x3a);
            break;
        }
        func_021C8838(w + 8, 2, 3);
        func_021C8860((struct S *)(w + 8), id);
        func_021C88C8(p, w);
        func_021C84E0(p, id);
        return 1;
    }
    return 0;
}
