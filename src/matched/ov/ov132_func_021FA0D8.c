/*
 * function: func_021FA0D8
 * address: 0x021FA0D8
 * packet: pkt_ov132_021FA0D8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05: needs per-function opt_common_subs off (the original does not share
 * idx*8 between the record stores and the call argument; without the pragma only
 * the rec/off register pair is swapped). Callee func_021FA3A8 takes (p, rec, type).
 * Caller passes q as a pointer: field 0x14 is a byte table read by MUSICAL_PROGRAM_GetCategoryBonus.
 * symbols:
 *   MUSICAL_PROGRAM_GetCategoryBonus 0x0215725C thumb ov010
 *   func_02005728 0x02005728 thumb
 *   func_021FA3A8 0x021FA3A8 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 MUSICAL_PROGRAM_GetCategoryBonus(u8 *, int);
extern u32 func_02005728(u32 range);
extern void func_021FA3A8(char *, u8 *, unsigned);
#pragma opt_common_subs off
void func_021FA0D8(char *p, char *q)
{
    u16 sum = 0;
    u8 b[4];
    u8 a[4] = {0, 0, 0, 0};
    u8 c[60];
    u8 n = 0;
    u8 i, j, k, g, x, idx;
    int base;
    u8 r;
    int off;
    u8 *rec;
    for (i = 0; i < 4; i++) {
        b[i] = MUSICAL_PROGRAM_GetCategoryBonus(*(u8 **)(q + 0x14), i);
        sum = sum + b[i];
    }
    for (i = 0; i < 4; i++) {
        a[i] = (b[i] * 60) / sum;
        n = n + a[i];
    }
    for (; n < 60; n++)
        a[func_02005728(4)]++;
    k = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < a[i]; j++) {
            c[k] = i;
            k++;
        }
    for (r = 0; r < 3; r++) {
        for (i = 0; i < 60; i++) {
            u8 t;
            x = func_02005728(60);
            t = c[i];
            c[i] = c[x];
            c[x] = t;
        }
    }
    for (g = 0; g < 5; g++) {
        i = 0;
        base = g * 12;
        for (; i < 12; i++) {
            idx = i + base;
            off = idx * 8;
            rec = (u8 *)(p + off);
            rec[0x20A] = i + 2;
            rec[0x20B] = g;
            rec[0x206] = c[idx];
            rec[0x205] = func_02005728(60) + 1;
            rec[0x204] = 0xff;
            if (i < 2)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 3);
            else if (i < 4)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 2);
            else if (i < 6)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 1);
            else
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 0);
        }
    }
}

#pragma opt_common_subs reset
