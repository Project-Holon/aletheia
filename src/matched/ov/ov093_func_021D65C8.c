/*
 * function: BTL_POKEPARAM_PassEffects
 * address: 0x021D65C8
 * packet: pkt_ov093_021D65C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned long loop index keeps its scaled offset in r7; direct u16 assignment truncates the first getter result before the second call.
 * symbols:
 *   func_021D66A0 0x021D66A0 thumb ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   BTL_POKEPARAM_SetContFlag 0x021D5FE4 thumb ov093
 *   BTL_POKEPARAM_GetStatRaw 0x021D58A8 thumb ov093
 *   BTL_POKEPARAM_SetStat 0x021D5970 thumb ov093
 *   BTL_POKEPARAM_ClearSubstitute 0x021D6D70 thumb ov093
 *   BTL_POKEPARAM_ClearSickConts 0x021D63B8 thumb ov093
 *   BTL_POKEPARAM_InitStatStages 0x021D53C0 thumb ov093
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Slot {u32 kind:3, rest:29;};
struct Byte7 {u8 v[7];};
struct Work {u8 pad[0x1c]; struct Slot slots[36]; u8 counters[36]; u8 padD0[0x2c]; struct Byte7 copy; u8 pad103[0xef]; u16 f1f2;};
extern int func_021D66A0(u32);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_POKEPARAM_SetContFlag(u8 *p, unsigned int n);
extern int BTL_POKEPARAM_GetStatRaw(u8 *, int);
extern void BTL_POKEPARAM_SetStat(u8 *, int, u16);
extern void BTL_POKEPARAM_ClearSubstitute(u8 *);
extern void BTL_POKEPARAM_ClearSickConts(u8 *p, int all);
extern void BTL_POKEPARAM_InitStatStages(unsigned char *p);
extern void MI_CpuFill8(void *, u8, u32);
void BTL_POKEPARAM_PassEffects(struct Work *p, struct Work *q)
{
    unsigned long i;
    u16 t;
    u16 t2;
    p->copy = q->copy;
    p->f1f2 = q->f1f2;
    for (i = 0; i < 36; i++) {
        if (q->slots[i].kind != 0 && func_021D66A0(i)) {
            p->slots[i] = q->slots[i];
            p->counters[i] = q->counters[i];
        }
    }
    if (BTL_POKEPARAM_TestContFlag((void *)q, 10)) {
        BTL_POKEPARAM_SetContFlag((u8 *)p, 10);
        t = BTL_POKEPARAM_GetStatRaw((u8 *)p, 8);
        t2 = BTL_POKEPARAM_GetStatRaw((u8 *)p, 9);
        BTL_POKEPARAM_SetStat((u8 *)p, 8, t2);
        BTL_POKEPARAM_SetStat((u8 *)p, 9, t);
    }
    if (BTL_POKEPARAM_TestContFlag((void *)q, 9)) BTL_POKEPARAM_SetContFlag((u8 *)p, 9);
    BTL_POKEPARAM_ClearSubstitute((u8 *)q);
    BTL_POKEPARAM_ClearSickConts((void *)q, 0);
    BTL_POKEPARAM_InitStatStages((unsigned char *)((char *)q + 0xfc));
    MI_CpuFill8((u8 *)q + 0x155, 0, 2);
}
