/*
 * function: ENCEFF_StartNameCutIn
 * address: 0x021F5398
 * packet: pkt_ov073_021F5398
 * region: ov073
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_AllocWork 0x021CF52C thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   ENCEFF_NameCutInEventMain 0x021F53C8 thumb ov073
 */
typedef unsigned int u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 *ENCEFF_AllocWork(void *,u32,u32);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int ENCEFF_NameCutInEventMain(void *,int *);
void *ENCEFF_StartNameCutIn(void *a,int unused,u32 b,u32 c) {
    u32 *w;
    w=ENCEFF_AllocWork((void *)FIELDMAP_GetEncEff((unsigned char *)((int)GAMESYSTEM_GetFieldMap(a))),12,0x50);
    w[0]=0; w[1]=b; w[2]=c;
    return func_020122C0(a,0,(void *)ENCEFF_NameCutInEventMain,0);
}
