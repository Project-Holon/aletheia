/*
 * function: MUSICAL_DRESSUP_SYS_Create
 * address: 0x02156CAC
 * packet: pkt_ov010_02156CAC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MUSICAL_SAVE_GetFromSave 0x0200A5F8 thumb
 *   sMusicalDressupSysFileName 0x02172730 data a1
 */
typedef struct Obj { int f00; int f04; int f08; } Obj;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *MUSICAL_SAVE_GetFromSave(void *sys);
extern const char sMusicalDressupSysFileName[];
Obj *MUSICAL_DRESSUP_SYS_Create(int a, int b, int c) { Obj *p; int zero = 0; p = func_02030734(a, 12, 0, sMusicalDressupSysFileName, 0xa7); p->f00 = zero; p->f08 = (int)MUSICAL_SAVE_GetFromSave((void *)c); p->f04 = b; return p; }
