/*
 * function: func_0689CCB4
 * address:  0x0689CCB4
 * packet:   pkt_0689CC8C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    unlabelled Thumb function after func_0689CC8C (its listing extent
 *           ran past it); seeded in layout/function_starts.txt.
 *
 * symbols:
 *   func_021B9A24  0x021B9A24  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;

struct S {
    u32 arr[16];
    u8 _40[0x42 - 0x40];
    u8 f42;
    u8 _43;
    u8 f44;
};

void MI_CpuFill8(void *p, int v, int n);
int BTL_POKEPARAM_IsFainted(u32 x);
int BTL_POKEPARAM_GetPokeId();
int func_021B9A24(int a, int b);
void func_0689CB3C(void *p);
void func_0689CB48(S *p, u32 id);
void func_0689CBB8(S *p, u32 id, u16 amt, int flag);
void func_0689CC14(S *p, u32 id);
u32 func_0689CC70(S *p, u32 i);
void func_0689CC84(char *p);
int func_0689CC8C(struct S *s);
#pragma opt_common_subs off
int func_0689CCB4(S *p, u32 id, u32 *out);
int func_0689CCF8(S *p, u32 id, u32 *out);
int func_0689CD38(S *p);
int func_0689CD40(S *p);
void func_0689CD48(S *p, u8 v);
int func_0689CD50(S *p);
int func_0689CD78(S *p, S *q);
int func_0689CDCC(S *p, int a, S *q);
int func_0689CE58(S *p, int a, S *q);

int func_0689CCB4(S *p, u32 id, u32 *out)
{
    u32 i;
    u32 t;
    for (i = 0; i < p->n; i++) {
        t = p->id[i];
        if (t == id && p->c[i] != 0) {
            *out = p->a[i] + p->b[i];
            return 1;
        }
    }
    return 0;
}
#pragma opt_common_subs reset
