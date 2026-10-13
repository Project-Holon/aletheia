/*
 * function: SCRCMD_SYMBOL_SetObjectPokemonWord
 * address:  0x0216AD1C
 * packet:   pkt_0216AD1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_SYMBOL_GetMmdl  0x0216AED0  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_SYMBOL_CreateObjectPokemon  0x0216AF1C  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   func_0201EE84  0x0201EE84  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_SYMBOL_GetMmdl(void *p, u32 id);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern int SCRCMD_SYMBOL_CreateObjectPokemon();
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern int func_020307B0();

int SCRCMD_SYMBOL_SetObjectPokemonWord(int a0, int a1, int a2, int a3)
{
    int v0;
    int t4;
    int t5;
    int t6;
    int t7;
    void *obj;
    void *v1;
t5 = a0 + 0;
t4 = a1 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0216AD26:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0216AD30:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t6 + 0;
    obj = SCRCMD_SYMBOL_GetMmdl((void *)a0, a1);
loc_0216AD3A:
    if (obj == 0) goto loc_0216AD6C;
loc_0216AD3E:
a0 = t4 + 0;
    a0 = SCRCMD_WORK_GetHeapId((void *)a0);
loc_0216AD44:
a2 = a0 + 0;
a0 = t4 + 0;
a3 = (int)&v0;
    a0 = SCRCMD_SYMBOL_CreateObjectPokemon(a0, obj, a2, a3);
loc_0216AD50:
t5 = a0 + 0;
    if (t5 == 0) goto loc_0216AD6C;
loc_0216AD54:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216AD5A:
    a0 = (int)SCRIPT_WORK_GetWordSet(v1);
loc_0216AD5E:
a1 = t7 + 0;
a2 = t5 + 0;
    func_0201EE84((void *)a0, a1, (void *)a2);
loc_0216AD66:
a0 = t5 + 0;
    a0 = func_020307B0(a0);
loc_0216AD6C:
a0 = 0;
    return a0;
}
