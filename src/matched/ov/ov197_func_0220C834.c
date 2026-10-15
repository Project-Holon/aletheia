/*
 * function: B_BAG_MAIN_Create
 * address: 0x0220C834
 * packet: pkt_ov197_0220C834
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Size constant held in a local (offsets derived from it), the 0x533 store repeated in each arm instead of one shared tail, and no row-pointer local in the first loop (*(u8 **)p re-read per argument).
 * symbols:
 *   d_0220E0E0 0x0220E0E0 data a1
 *   func_02030734 0x02030734 arm
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   B_BAG_MAIN_Main 0x0220C914 thumb ov197
 *   func_0200829C 0x0200829C thumb
 *   func_020082B0 0x020082B0 thumb
 *   func_020082B4 0x020082B4 thumb
 *   B_BAG_MAIN_CheckKeyItem 0x0220B9A4 thumb ov197
 */


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_0220E0E0[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *BTLV_EFFECT_GetOwner(void);
typedef signed short   s16;
struct MyItemSave;
extern int BTLV_EFFECT_GetPalanm(void);
extern void *func_02030DA8(void *, u32, void *, u32);
extern void B_BAG_MAIN_Main(void *task, char *p);
extern void func_0200829C(const struct MyItemSave *p, int i, s16 *a, s16 *b);
extern u16 func_020082B0(const struct MyItemSave *p);
extern u16 func_020082B4(const struct MyItemSave *p);
extern int B_BAG_MAIN_CheckKeyItem(char *p);

void B_BAG_MAIN_Create(u8 *arg)
{
    u8 *p;
    u8 *q;
    int z;
    u32 i;
    int v;
    int sz = 0x5A4;
    p = func_02030734(*(u16 *)(arg + 0xc), sz, 1, d_0220E0E0, 0xB1);
    q = func_02030DA8(BTLV_EFFECT_GetOwner(), (u32)B_BAG_MAIN_Main, p, 0x64);
    *(u8 **)p = arg;
    *(void **)(p + 8) = (void *)BTLV_EFFECT_GetPalanm();
    z = 0;
    *(int *)(p + sz - 4) = z;
    if (*(int *)(*(u8 **)p + 8) == 1) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = 1;
        p[sz - 0x71] = z;
    } else if (*(int *)(*(u8 **)p + 8) == 3) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = z;
        z = 2;
        p[sz - 0x71] = z;
    } else {
        p[sz - 0x72] = z;
        p[sz - 0x74] = z;
        p[sz - 0x71] = z;
    }
    if (*(int *)(*(u8 **)p + 8) != 1) {
        for (i = 0; i < 4; i++) {
            func_0200829C((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)), (u16)i, (s16 *)(*(u8 **)p + 0x30 + i * 2), (s16 *)(*(u8 **)p + 0x38 + i * 2));
        }
        *(u16 *)(p + 0x540) = func_020082B0((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        p[0x542] = func_020082B4((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        B_BAG_MAIN_CheckKeyItem((char *)p);
    } else {
        for (i = 0; i < 4; i++) {
            *(u16 *)(*(u8 **)p + i * 2 + 0x30) = 0;
            *(u16 *)(*(u8 **)p + i * 2 + 0x38) = 0;
        }
    }
}
