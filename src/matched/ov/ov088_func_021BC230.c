/*
 * function: func_021BC230
 * address:  0x021BC230
 * packet:   pkt_ov088_021BC230
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case bodies are laid out in source order, and the original places
 * case 6 before case 5 (jump table at 0x021BC254).
 *
 * symbols:
 *   func_021BD2F4  0x021BD2F4  thumb  ov088
 *   func_02031330  0x02031330  arm
 *   func_02031348  0x02031348  arm
 *   func_02008550  0x02008550  thumb
 *   func_021BC4A4  0x021BC4A4  thumb  ov088
 *   ov204_id       0x000000CC  data
 *   ov194_id       0x000000C2  data
 *   d_021BFD24     0x021BFD24  data  ov204  a4
 *   d_021F5580     0x021F5580  data  ov194  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021BD2F4(void *p);
extern unsigned int func_02031330(void *p);
extern void func_02031348(u32 h, void *id, void *proc, void *arg);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_021BC4A4(int a, int b, int c);
extern u8 ov204_id[];
extern u8 ov194_id[];
extern char d_021BFD24[];
extern char d_021F5580[];

int func_021BC230(void *a0, int *seq, void *a2, char *w)
{
    int busy;

    func_021BD2F4(*(void **)(w + 0x2c));
    busy = func_02031330((void *)*(u32 *)(w + 0x30));
    switch (*seq) {
    case 0:
        func_02031348(*(u32 *)(w + 0x30), ov204_id, d_021BFD24, w + 0x10);
        *seq = 1;
        break;
    case 1:
        if (busy != 1)
            *seq = 2;
        break;
    case 2:
        *(u16 *)(*(char **)(w + 0x28) + 4) = func_02008550((const struct Sub0200852CObj *)(*(int *)(w + 0x8)));
        *(u32 *)(*(char **)(w + 0x28) + 0x24) = *(u32 *)(w + 0x2c);
        func_02031348(*(u32 *)(w + 0x30), ov194_id, d_021F5580, *(void **)(w + 0x28));
        *seq = 3;
        break;
    case 3:
        if (busy != 1)
            *seq = 4;
        break;
    case 4:
        func_021BC4A4(*(int *)(w + 0x54), *(int *)(*(char **)(w + 0x28) + 0x20),
                      func_02008550((const struct Sub0200852CObj *)(*(int *)(w + 0x54))));
        *(u32 *)(w + 0x18) = 7;
        func_02031348(*(u32 *)(w + 0x30), ov204_id, d_021BFD24, w + 0x10);
        *seq = 6;
        break;
    case 6:
        if (busy != 1)
            *seq = 5;
        break;
    case 5:
        if (*(u32 *)(w + 0x24) == 0)
            *seq = 7;
        else
            *seq = 2;
        break;
    case 7:
        return 1;
    }
    return 0;
}
