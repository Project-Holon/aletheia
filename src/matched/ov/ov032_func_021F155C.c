/*
 * function: BEACON_VIEW_StartEntrySlide
 * address:  0x021F155C
 * packet:   pkt_ov032_021F155C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_StartEntrySlide 0x021F155C thumb
 *   BEACON_VIEW_IconSlideTask 0x021F1704 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0207C768 0x0207C768 arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void BEACON_VIEW_IconSlideTask(void *h, char *t);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern u32 func_0207C768(u32 a, u32 b);

#define FX32_CONST(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

void BEACON_VIEW_StartEntrySlide(char *p, u8 *e, int mode, u8 delay, int *r)
{
    u8 *t;

    t = TCBL_GetWork(TCBL_AddTask(*(u32 *)(p + 0xa0), (void *)BEACON_VIEW_IconSlideTask, 0x28, 0));
    MI_CpuFill8(t, 0, 0x28);
    t[0xc] = mode;
    if (t[0xc] == 0) {
        e[2] = e[2] - 1;
    } else if (t[0xc] == 1) {
        e[2] = e[2] + 1;
    }
    *(char **)(t + 4) = p;
    *(u8 **)(t + 8) = e;
    *(s16 *)(t + 0x10) = (1 - e[2]) * -13;
    *(s16 *)(t + 0x12) = (1 - e[2]) * -40;
    *(int *)(t + 0x14) = FX32_CONST(*(s16 *)(e + 8));
    *(int *)(t + 0x18) = FX32_CONST(*(s16 *)(e + 0xa));
    t[0xe] = 8;
    t[0xd] = delay;
    *(int *)(t + 0x1c) = func_0207C768(FX32_CONST(*(s16 *)(t + 0x10) - *(s16 *)(e + 8)), FX32_CONST(t[0xe]));
    *(int *)(t + 0x20) = func_0207C768(FX32_CONST(*(s16 *)(t + 0x12) - *(s16 *)(e + 0xa)), FX32_CONST(t[0xe]));
    *(int **)(t + 0x24) = r;
    (*r)++;
}
