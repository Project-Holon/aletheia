/*
 * function: func_0217D4FC
 * address: 0x0217D4FC
 * packet: pkt_ov176_0217D4FC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217DC28 0x0217DC28 thumb ov176
 *   func_0217DEA4 0x0217DEA4 thumb ov176
 *   func_0217DE8C 0x0217DE8C thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   func_0217E000 0x0217E000 thumb ov176
 *   func_0217DFF0 0x0217DFF0 thumb ov176
 *   func_0217DFD0 0x0217DFD0 thumb ov176
 *   func_0217DFE4 0x0217DFE4 thumb ov176
 *   func_0217DEDC 0x0217DEDC thumb ov176
 *   func_0217DFBC 0x0217DFBC thumb ov176
 *   func_0217DFA8 0x0217DFA8 thumb ov176
 *   func_0217DE98 0x0217DE98 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217DC20 0x0217DC20 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 */
typedef unsigned int u32;
extern void func_0217DC28(int *);
extern void func_0217DEA4(int *, int);
extern int func_0217DE8C(int *);
typedef signed int     s32;
typedef unsigned char  u8;
struct Big;
struct Rec160;
struct Reg2;
extern u32 KEY_GetTrg(void);
extern void func_0217E000(int *);
extern int func_0217DFF0(int, int);
extern void func_0217DFD0(int *, int, int);
extern int func_0217DFE4(int *);
extern void func_0217DEDC(char *, int);
extern int func_0217DFBC(int *);
extern void func_0217DFA8(int *);
extern int func_0217DE98(int *);
extern void func_021E8AA0(int *, int);
extern void func_0217DC20(int a);
extern void func_021E8AB4(u32, u32);
extern void func_021E8AB8(u32);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200B358(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_0200BAC8(void *);
struct Obj;
extern void func_0200BBD8(struct Obj *p, int v);
extern void func_0200B110(struct Reg2 *p, u32 id, s32 value);
extern int GAME_DATA_SaveStart(int a0);
extern int GAME_DATA_SaveMain(u8 *p);
void func_0217D4FC(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4(p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x67, 1);
        *state = 19; func_021E8AB4((u32)a, 4); break;
    case 4: func_0217DEDC((char *)p, 2); *state = 5; break;
    case 5:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: func_0217DFD0(p, 0x71, 1); *state = 19; func_021E8AB4((u32)a, 7); break;
    case 7: func_0217DEDC((char *)p, 0); *state = 8; break;
    case 8:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: func_0217DFD0(p, 0x72, 1); *state = 19; func_021E8AB4((u32)a, 10); break;
    case 10: func_0217DEDC((char *)p, 0); *state = 11; break;
    case 11:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: func_0217DFD0(p, 0x6B, 2); *state = 19; func_021E8AB4((u32)a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p[12]);
        record = func_0200B1D4(func_0200B358(base), p[5]);
        base = func_0200BAC8(base);
        func_0200BBD8(base, p[5] == 0 ? 1 : 2);
        func_0200B110(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart((int)((void *)p[12])); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: func_0217DFD0(p, 0x73, 1); *state = 19; func_021E8AB4((u32)a, 17); break;
    case 17: if (func_0217DE98(p)) *state = 18; break;
    case 18: func_021E8AA0(a, (int)func_0217DC20); break;
    case 19: if (func_0217DFE4(p)) func_021E8AB8((u32)a); break;
    }
}
