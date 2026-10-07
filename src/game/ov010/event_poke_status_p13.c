/*
 * file:     event_poke_status_p13.c
 * unit:     yes
 * function: func_02159FE0, func_0215A014, func_0215A048
 * address:  0x02159FE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02170FEC     0x02170FEC  data  ov010  a4
 *   func_0201296C 0x0201296C thumb
 *   func_02014314 0x02014314 thumb
 *   func_02014184 0x02014184 thumb
 */
#include "../../matched/include/G_ov010_02170FEC.h"

struct BigObj;
typedef unsigned short u16;

typedef struct Ent_02159FE0 {
    u16 h0;
    u16 on : 1;
    u16 h4;
    char pad[0x14 - 6];
} Ent_02159FE0;

typedef struct Ent_0215A014 { u16 h0; u16 unused:1; u16 on:1; u16 rest:14; u16 h4, h6, h8; char pad[10]; } Ent_0215A014;

typedef unsigned int   u32;

extern u32 func_0201296C(const struct BigObj *p);
extern void func_02014314(char *, int);
extern void func_02014184(void *, int, short, int, int, int);
int func_02159FE0(int v);
void func_0215A014(void *a, int b);
void func_0215A048(void *a, int b, int c, unsigned d, u16 e);
extern Ent_02159FE0 d_02170FEC[];


/*
 * Unlabelled leaf (push {r4,r5} only, so disasm.py prints it as .word
 * data): a 1-based index lookup over a 17-entry, 0x14-byte table.
 * Callee of ov020 func_021857C0.
 */
int func_02159FE0(int v)
{
    unsigned int i;

    for (i = 0; i < 17; i++) {
        if (v == d_02170FEC[i].h4 && d_02170FEC[i].on)
            return i + 1;
    }
    return 0;
}

void func_0215A014(void *a, int b) {
 unsigned i;
 Ent_0215A014 *p;
 for(i=0; i<17; i++) {
 p = &((Ent_0215A014 *)d_02170FEC)[i];
 if (b == p->h8 && p->on) {
 func_02014314((char *)func_0201296C(a), p->h0);
 return;
 }
 }
}

/*
 * evidence: owner commit f860957 supplies the matched ARM9 Thumb02014184
 * witness. Recheck the caller against that witness; no owner C compiled.
 * prototype: owner's u16 id is widened to int here because original r1
 * is passed unchanged without narrowing. Remaining payloads retain 32 bits.
 * prior: wave49 one MATCH; tu --suggest-split left caller OUT.
 */
void func_0215A048(void *a, int b, int c, unsigned d, u16 e) {
 func_02014184(a, b, 1, d << 16, 0, (unsigned)e << 16);
}
