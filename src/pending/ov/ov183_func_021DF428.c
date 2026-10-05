/*
 * function: func_021DF428
 * address: 0x021DF428
 * packet: pkt_ov183_021DF428
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wave P6 lane U1): new draft, no earlier source. Types from matched
 * ov183 021DF1DC (Menu: base at +0xD0) and 021DF620 (State layout: indices at
 * +0x18, cursor +0x54, sprites +0x58, source +0xD0, entry rows 0xC4 apart).
 * DIFF 24 B, only spill-slot residue. The original keeps the clamped count n
 * at [sp,#0x18], below the four loop temps (row, row2, j*4, &indices[i][j]) at
 * 0x1C..0x28; ours puts n at 0x28 and the temps at 0x18..0x24. The entry
 * stores also differ: original spills p, heap, then mgr; ours p, mgr, then heap.
 * Closed here: final call as if/else with a call in each arm (ternary hoisted
 * movs r1,#1), short y field (asrs), archive/i slots. Tried without effect:
 * n declared first or last, static inline clamp helper with and without a named
 * n, u8 n (126 B worse), block-scope n, inline helper in the loop test (374 B
 * worse), per-function pragmas opt_lifetimes, opt_propagation, opt_common_subs,
 * opt_dead_assignments, scheduling, peephole (24 B or much worse).
 * Unlabelled callees named by address; all 16 relocs resolve.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DF838 0x021DF838 thumb ov183
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; void *sprites[5][6]; char *source; };
struct Pos { u16 x; short y; u16 z; u8 a,b; };
struct Entries { u32 species[6],form[6],gender[6]; };
extern void *func_020490F4(u32,u16);
extern u32 func_0201BC3C(void),func_0201BC40(void),func_0201BCB4(void);
extern u32 func_0204ACEC(void *,u32,u32,u32,u32),func_0204AF28(void *,u32,u32,u32);
extern void func_02082BCC(void *,u32,u32);
extern void func_021DF838(char *,struct Entries *);
extern u32 func_0201BABC(u32,u32,u32,u32),func_0201BB5C(u32,u32,u32,u32);
extern u32 func_0204A6C8(void *,u32,u32,u32,u32);
extern void *func_0204B294(u32,u32,u32,u32,struct Pos *,u32,u32);
extern void func_0204B6F4(void *,u32,u32),func_0204B688(void *,u32),func_0204B3DC(void *,u32);
extern void func_02049238(void *);
void func_021DF428(struct State *p,u32 mgr,u32 heap)
{
    int i,j;
    void *archive;
    u32 mode,species;
    int n;
    struct Entries e;
    struct Pos pos;
    n=*(int *)(p->source+0x1718);
    if(n>=5) n=5;
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,mode);
    i=0;
    p->shared0=func_0204ACEC(archive,func_0201BC3C(),0,0x80,heap);
    p->shared1=func_0204AF28(archive,func_0201BC40(),func_0201BCB4(),heap);
    func_02082BCC(&pos,0,8);
    pos.z=1;
    pos.a=i;
    pos.b=i;
    for(i=0;i<n;i++) {
        func_021DF838(p->source+i*0xc4,&e);
        for(j=0;j<6;j++) {
            species=e.species[j];
            if(species==0) species=1;
            p->indices[i][j]=func_0204A6C8(archive,func_0201BABC(species,e.form[j],e.gender[j],0),0,0,heap);
            pos.x=j*0x18+0x6e;
            pos.y=i*0x18+0x48;
            pos.a=6-j;
            p->sprites[i][j]=func_0204B294(mgr,p->indices[i][j],p->shared0,p->shared1,&pos,0,heap);
            func_0204B6F4(p->sprites[i][j],func_0201BB5C(species,e.form[j],e.gender[j],0),0);
            func_0204B688(p->sprites[i][j],1);
            if(e.species[j]==0) func_0204B3DC(p->sprites[i][j],0);
            else func_0204B3DC(p->sprites[i][j],1);
        }
    }
    func_02049238(archive);
}
