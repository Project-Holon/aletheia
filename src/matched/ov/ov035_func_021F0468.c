/*
 * function: func_021F0468
 * address:  0x021F0468
 * packet:   pkt_ov035_021F0468
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0468 0x021F0468 thumb
 *   func_021F0254 0x021F0254 thumb ov035
 *   func_021F02FC 0x021F02FC thumb ov035
 *   func_021F0340 0x021F0340 thumb ov035
 *   func_021F0354 0x021F0354 thumb ov035
 *   func_021F0364 0x021F0364 thumb ov035
 *   func_021F0370 0x021F0370 thumb ov035
 *   func_020221A4 0x020221A4 thumb
 *   func_02012204 0x02012204 thumb
 *   func_02026454 0x02026454 thumb
 *   func_02026400 0x02026400 thumb
 *   func_02012158 0x02012158 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F0254(char *p, int a1, int a2);
extern void func_021F02FC(char *p, int a1);
extern void func_021F0340(char *p);
extern void func_021F0354(char *p);
extern u8 func_021F0364(char *p);
extern u32 func_021F0370(char *p);
extern u32 func_020221A4(void);
extern u32 func_02012204(void *p);
extern u32 func_02026454(void *h);
extern void func_02026400(void *h);
extern void func_02012158(void *p, u32 v);

int func_021F0468(char *p)
{
    u16 v;

    switch (*(u16 *)(p + 0x4A)) {
    case 0:
        func_021F0254(p, *(int *)(p + 0x18), 2);
        func_021F0254(p, *(int *)(p + 0x1C), 3);
        func_021F02FC(p, *(u16 *)p);
        (*(u16 *)(p + 0x4A))++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (*(u16 *)(p + 0x4A))++;
        break;
    case 2:
        if (func_021F0370(p) != 0 || func_02012204(*(void **)(p + 4)) == 1) {
            if (func_021F0364(p) == 0 || func_02012204(*(void **)(p + 4)) == 1) {
                if (func_02026454(*(void **)(p + 8)))
                    func_02026400(*(void **)(p + 8));
                v = 1;
            } else {
                v = 0;
            }
            *(u16 *)(p + 0x4C) = v;
            *(u16 *)(p + 0x4A) = 3;
            func_021F0340(p);
        }
        break;
    case 3:
        if (*(u16 *)(p + 0x4C) != 0) {
            if (func_02026454(*(void **)(p + 8)) != 0)
                break;
            func_02012158(*(void **)(p + 4), 0);
        }
        (*(u16 *)(p + 0x4A))++;
        break;
    case 4:
        return 1;
    }
    func_021F0354(p);
    return 0;
}
