/*
 * function: func_021BA0B0
 * address:  0x021BA0B0
 * packet:   pkt_ov218_021BA0B0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021B9924 0x021B9924 thumb ov218
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   func_021B9C00 0x021B9C00 thumb ov218
 *   func_021B9C88 0x021B9C88 thumb ov218
 *   func_021B9898 0x021B9898 thumb ov218
 *   func_0204E804 0x0204E804 arm
 *   func_02024004 0x02024004 thumb
 *   func_0201F048 0x0201F048 thumb
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021B61FC(u8 *a);
extern void func_021B6200(u8 *a);
extern void func_021B9924(void);
extern void func_021B9B78(u8 *p, u32 v);
extern u32 func_021B9C00(u8 *p);
extern u32 func_021B9C88(u8 *p);
extern u32 func_021B9898(u32 a, u32 b, u32 c);
extern u32 func_0204E804(void);
extern u32 func_02024004(u32 v);
extern void func_0201F048(u32 a, u32 b, u32 c);
extern int tbl_021BAC80[];
u32 func_021BA0B0(u8 *a, u8 *b)
{
    switch (func_021B61FC(a)) {
    case 0:
        func_021B9924();
    tail:
        func_021B6200(a);
        break;
    case 1:
        if (func_0204E804() == 1) break;
        if (func_02024004(1) == 0) break;
        func_0201F048(*(u32 *)(*(u8 **)(b + 0x28) + 0x14), 0, tbl_021BAC80[*(int *)(b + 0x30)]);
        func_021B9B78(*(u8 **)(b + 0x28), 0xEA);
        goto tail;
    case 2:
        if (func_021B9C00(*(u8 **)(b + 0x28)) == 0) break;
        goto tail;
    case 3:
        *(u32 *)(b + 0x1C) = func_021B9898(*(u32 *)(b + 0x18), func_021B9C88(*(u8 **)(b + 0x28)), *(u16 *)b);
        return 1;
    }
    return 0;
}
