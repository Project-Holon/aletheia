/*
 * function: FIELD_WFBC_SetWordSetParentName
 * address:  0x02193B68
 * packet:   pkt_ov021_02193B68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_LoadSaveData  0x02193EB4  thumb  ov021
 *   FIELD_WFBC_FindPeopleByNpcId  0x02193F34  thumb  ov021
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Init  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_0200852C  0x0200852C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj19617.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct V;
extern void FIELD_WFBC_LoadSaveData(struct V *v);
struct E50;
extern struct E50 *FIELD_WFBC_FindPeopleByNpcId(struct V *v, u32 key);
struct Sub0200852CObj;
struct WordSet;
extern void *MYSTATUS_Create(int a0);
struct Sub0200852CObj;
extern void MYSTATUS_Init(struct Sub0200852CObj *);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u32 func_020307B0(void *p);

void FIELD_WFBC_SetWordSetParentName(void *a, int b, int c, int d, u16 e)
{
    char *q;
    int h;

    FIELD_WFBC_LoadSaveData(a);
    q = (char *)FIELD_WFBC_FindPeopleByNpcId(a, c);
    h = (int)MYSTATUS_Create((u16)((e & 0x7fff) | 0x8000));
    MYSTATUS_Init((struct Sub0200852CObj *)h);
    func_020084D4(h, q + 0x38);
    func_0200852C((struct Sub0200852CObj *)h, ((struct Obj19617 *)q)->f48);
    WORDSET_SetSlotMyStatus((struct WordSet *)b, d, (void *)h);
    func_020307B0((void *)h);
}
