/*
 * function: func_0217CC78
 * address: 0x0217CC78
 * packet: pkt_ov176_0217CC78
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 0200AE14 leaves supplied pointer in r0 despite its void own declaration.
 * symbols:
 *   func_0217D160 0x0217D160 thumb ov176
 *   func_0200B078 0x0200B078 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200E918 0x0200E918 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_0200B110 0x0200B110 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_0217D1A0 0x0217D1A0 thumb ov176
 *   func_0217CEAC 0x0217CEAC thumb ov176
 *   func_0217CFDC 0x0217CFDC thumb ov176
 *   func_0217CFD0 0x0217CFD0 thumb ov176
 *   func_0217D194 0x0217D194 thumb ov176
 *   func_0217D174 0x0217D174 thumb ov176
 *   func_0200BA38 0x0200BA38 thumb
 *   func_0217D010 0x0217D010 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217C2EC 0x0217C2EC thumb ov176
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0217D160(int *);
extern int func_0200B078(void *, u32);
extern void *func_0200AE14(void *);
extern u8 func_0200E918(const u8 *, u32);
extern u32 func_0200AE54(void *, u32);
extern void func_0217CFE8(void *, int, int);
extern void func_021E8AB4(u32, u32);
extern void func_0200B110(void *, u32, int);
extern void *func_02012EBC(void *);
extern void *func_0200BAC8(void *);
extern void func_0200BBD8(void *, int);
extern void func_02012DAC(void *);
extern int func_02012DD0(void *);
extern void func_0217D1A0(u8 *, int);
extern void func_0217CEAC(u8 *, int);
extern int func_0217CFDC(int *);
extern void func_0217CFD0(int *);
extern int func_0217D194(int *);
extern void func_0217D174(int *);
extern u32 func_0200BA38(u8);
extern void func_0217D010(u8 *, int);
extern void func_021E8AA0(int *, int);
extern void func_0217C2EC(void);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
void func_0217CC78(int *a, int *state, u8 *p)
{
    void *record;
    u32 value;
    int result;
    switch (*state) {
    case 0:
        func_0217D160((int *)p);
        if (func_0200B078(*(void **)(p + 0x38), 10) == 3) *state = 6;
        else *state = 1;
        break;
    case 1:
        record = func_0200AE14(*(void **)(p + 0x38));
        value = func_0200E918(*(u8 **)(p + 0x34), 0);
        if (value >= func_0200AE54(record, 0x16)) *state = 2;
        else *state = 16;
        break;
    case 2: func_0217CFE8(p, 10, 2); *state = 17; func_021E8AB4((u32)a, 3); break;
    case 3:
        func_0200B110(*(void **)(p + 0x38), 10, 3);
        func_0200BBD8(func_0200BAC8(func_02012EBC(*(void **)(p + 0x1B8))), 2);
        func_02012DAC(*(void **)(p + 0x1B8)); *state = 4; break;
    case 4:
        switch (func_02012DD0(*(void **)(p + 0x1B8))) {
        case 0: case 1: break;
        case 2: case 3: *state = 5; break;
        }
        break;
    case 5: func_0217D1A0(p, 1); func_0217CFE8(p, 25, 1); *state = 17; func_021E8AB4((u32)a, 6); break;
    case 6: func_0217CFE8(p, 29, 1); *state = 17; func_021E8AB4((u32)a, 7); break;
    case 7: func_0217CEAC(p, 2); *state = 8; break;
    case 8:
        result = func_0217CFDC((int *)p);
        if (result != -1) {
            func_0217CFD0((int *)p);
            if (*(int *)(p + 0x1D0) && *(int *)(*(u8 **)(p + 0x1C4) + 12) == 0) {
                switch (result) { case 0: *state = 11; break; case 1: *state = 9; break; }
            } else if (result == 0) *state = 9;
        }
        break;
    case 9: func_0217CFE8(p, 31, 1); *state = 17; func_021E8AB4((u32)a, 10); break;
    case 10: if (func_0217D194((int *)p)) { func_0217D174((int *)p); *state = 15; } break;
    case 11:
        if (func_0200BA38(*(u32 *)(*(u8 **)(p + 0x1C0) + 0x44))) *state = 12;
        else *state = 13;
        break;
    case 12: func_0217CFE8(p, 16, 1); *state = 17; func_021E8AB4((u32)a, 14); break;
    case 13: func_0217CFE8(p, 34, 1); *state = 17; func_021E8AB4((u32)a, 6); break;
    case 14: func_0217D010(p, 4); break;
    case 15: func_0217D010(p, 1); break;
    case 16: func_021E8AA0(a, (int)func_0217C2EC); break;
    case 17: if (func_0217D000(p)) func_021E8AB8((u32)a); break;
    }
}
