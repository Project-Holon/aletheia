/*
 * function: FIELD_ENCOUNT_PickWfbcMon
 * address:  0x021A9604
 * packet:   pkt_ov021_021A9604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FIELD_WFBC_GetPeople  0x0219390C  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetNpcRecord  0x02193C00  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sel {
    u8 pad00[8];
    int f08;
};

struct Out {
    u16 f00;
    u16 f02;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
};

extern void *FIELD_WFBC_GetPeople(void *a, u32 b);
extern u8 *FIELD_WFBC_PEOPLE_GetNpcRecord(int a);
extern u32 func_020056EC(u32 v);
extern void func_02082BCC(void *p, int v, int n);

u32 FIELD_ENCOUNT_PickWfbcMon(int obj, struct Sel *sel, struct Out *out)
{
    u32 k;
    u32 sum;
    u32 r;
    int i;
    u8 *q;
    int p;

    switch (sel->f08) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    case 3:
        k = 2;
        break;
    case 0xFF:
        return 0;
    }
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)FIELD_WFBC_GetPeople((void *)obj, i);
        if (p) {
            sum += FIELD_WFBC_PEOPLE_GetNpcRecord(p)[k + 0x14];
        }
    }
    r = func_020056EC(sum);
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)FIELD_WFBC_GetPeople((void *)obj, i);
        if (p) {
            q = FIELD_WFBC_PEOPLE_GetNpcRecord(p);
            sum += q[k + 0x14];
            if (r < sum) {
                func_02082BCC(out, 0, 0x14);
                out->f00 = ((u16 *)(q + 8))[k];
                out->f04 = (q + k)[0x10];
                return 1;
            }
        }
    }
    return 0;
}
