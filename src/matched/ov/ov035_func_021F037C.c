/*
 * function: func_021F037C
 * address:  0x021F037C
 * packet:   pkt_ov035_021F037C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F037C 0x021F037C thumb
 *   func_021F0254 0x021F0254 thumb ov035
 *   func_021F0298 0x021F0298 thumb ov035
 *   func_021F02FC 0x021F02FC thumb ov035
 *   func_021F0340 0x021F0340 thumb ov035
 *   func_021F0354 0x021F0354 thumb ov035
 *   func_021F0364 0x021F0364 thumb ov035
 *   func_021F0370 0x021F0370 thumb ov035
 *   func_020221A4 0x020221A4 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02012204 0x02012204 thumb
 *   func_02026454 0x02026454 thumb
 *   func_02026400 0x02026400 thumb
 *   func_02012158 0x02012158 thumb
 *   func_020121CC 0x020121CC thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F0254(char *p, int a1, int a2);
extern void func_021F0298(char *p, int a1, int a2, int a3);
extern void func_021F02FC(char *p, int a1);
extern void func_021F0340(char *p);
extern void func_021F0354(char *p);
extern u8 func_021F0364(char *p);
extern u32 func_021F0370(char *p);
extern u32 func_020221A4(void);
extern u32 func_02035C60(void);
struct Comm;
struct Ctx;
struct IcaAnime;
extern u32 func_02012204(const struct Ctx *p);
extern u32 func_02026454(void *h);
extern void func_02026400(struct Comm *p);
extern void func_02012158(char *p, unsigned int v);
extern u32 func_020121CC(struct IcaAnime *p);

int func_021F037C(char *p)
{
    u16 v;

    switch (*(u16 *)(p + 0x4A)) {
    case 0:
        func_021F0254(p, *(int *)(p + 0x18), 0);
        func_021F0254(p, *(int *)(p + 0x1C), 3);
        func_021F02FC(p, *(u16 *)p);
        (*(u16 *)(p + 0x4A))++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (*(u16 *)(p + 0x4A))++;
        break;
    case 2:
        if (func_021F0370(p) != 0) {
            if (func_021F0364(p) == 0) {
                func_02012158(*(void **)(p + 4), 1);
                func_020121CC(*(void **)(p + 4));
                v = 3;
            } else {
                v = 5;
            }
            *(u16 *)(p + 0x4A) = v;
            func_021F0340(p);
        }
        break;
    case 3:
        func_021F0298(p, *(int *)(p + 0x18), 1, 6);
        (*(u16 *)(p + 0x4A))++;
        break;
    case 4:
        if (func_02035C60() != 0 || func_02012204(*(void **)(p + 4)) != 0)
            (*(u16 *)(p + 0x4A))++;
        break;
    case 5:
        if (func_02012204(*(void **)(p + 4)) != 0) {
            if (func_02026454(*(void **)(p + 8)))
                func_02026400(*(void **)(p + 8));
            *(u16 *)(p + 0x4A) = 6;
            break;
        }
        return 1;
    case 6:
        if (func_02026454(*(void **)(p + 8)) == 0)
            return 1;
        break;
    }
    func_021F0354(p);
    return 0;
}
