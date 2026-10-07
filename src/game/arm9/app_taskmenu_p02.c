/*
 * file:     app_taskmenu_p02.c
 * unit:     yes
 * function: func_020275E4, func_020275E8, func_020275EC, func_020275F8, func_020275FC, func_02027600, func_02027604, func_02027610, func_02027614, func_02027618, func_0202761C, func_02027620, func_02027624, func_02027628, func_0202762C, func_02027630, func_02027634, func_02027694, func_02027698, func_0202769C, func_020276A0, func_020276A4, func_020276A8, func_020276AC, func_020276B0, func_020276B4, func_020276B8, func_020276BC, func_020276C0, func_020276C4, func_02027710, func_02027714, func_02027718, func_0202771C, func_02027720, func_0202772C, func_02027738, func_02027740, func_02027748, func_0202774C, func_02027750, func_02027754, func_02027758, func_0202775C, func_02027760, func_02027764, func_02027768, func_0202776C, func_02027770, func_02027774, func_02027778, func_0202784C, func_02027858, func_020278F4, func_02027974, func_020279E8, func_02027A04, func_02027A08
 * address:  0x020275E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0209FCF8  0x0209FCF8  data
 *   d_0209FCEC  0x0209FCEC  data
 *   func_0204162C  0x0204162C  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030734     0x02030734  arm
 *   MIi_CpuCopy16     0x02082A60  arm
 *   func_02027a24     0x02027A24  thumb
 *   func_020355c4     0x020355C4  arm
 *   func_02027b30     0x02027B30  thumb
 *   sFile_020A74E0    0x020A74E0  data
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02027D44  0x02027D44  thumb
 *   func_02027E3C  0x02027E3C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02027B30  0x02027B30  thumb
 *   func_02027B60  0x02027B60  thumb
 */
#include "../../matched/include/Obj00059.h"
#include "../../matched/include/Obj00104.h"

struct Cfg;
struct Obj;
struct S;
struct Descriptor;
struct PrintSys;
struct Menu;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

struct BeaconGfx {
    u8  pad[0x540];
    u16 pal[0x60];
};

struct TaskMenuTmpl
{
  u32 heapId;
  u8 count;
  u8 pad05[3];
  const void *unk08;
  u32 unk0c;
  u8 pad10[2];
  u8 unk12;
  u8 unk13;
};

struct TaskMenuOwner {
  u8 pad_00[0x14];
  void *unk_14;
};

struct TaskMenu
{
  u8 unk00;
  u8 unk01;
  u16 unk02;
  u16 unk04;
  u16 unk06;
  u32 unk08;
  u32 unk0c;
  u32 unk10;
  u32 unk14;
  void **buf1;
  void *buf2;
  struct TaskMenuTmpl tmpl;
  void *arg1;
};

extern u32 func_0204162C(int channel);
extern void *func_02049EF4(void *arc, u32 id, u32 comp, void **out, u32 heap);
extern void  func_02082D44(void *dst, const void *src, u32 size);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void func_02027a24(struct Obj *o, struct Cfg *cfg);
extern u8 func_020355c4(void);
extern void func_02027b30(u32 a0, struct S *s, int mode);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02041B6C(u32 bit);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_02027D44(struct Menu *m);
extern void func_02027E3C(u8 *m);
extern u32  _u32_div_f(u32 a, u32 b);
extern u32 func_02027B30(u32 a, struct S *s, int mode);
extern void func_02027B60(u16 *phase, u16 *out, u32 mode, u32 slot);
u32 func_020275E4(void);
u32 func_020275E8(void);
u8 func_020275EC(int i);
u32 func_020275F8(u32 a);
u32 func_020275FC(u32 a);
u32 func_02027600(u32 a);
u8 func_02027604(u8 i);
u32 func_02027610(u32 a);
u32 func_02027614(void);
u32 func_02027618(void);
u32 func_0202761C(u32 a);
u32 func_02027620(u32 a);
u32 func_02027624(void);
u32 func_02027628(void);
u32 func_0202762C(void);
u32 func_02027630(void);
void func_02027634(void *arc, int id, u32 heap, int base, u32 pal);
u32 func_02027694(void);
u32 func_02027698(void);
u32 func_0202769C(u32 i);
u32 func_020276A0(u32 i);
u32 func_020276A4(void);
u32 func_020276A8(void);
u32 func_020276AC(u32 i);
u32 func_020276B0(u32 i);
u32 func_020276B4(void);
u32 func_020276B8(void);
u32 func_020276BC(u32 i);
u32 func_020276C0(u32 i);
int func_020276C4(int a0);
int func_02027710(int a);
int func_02027714(int a);
int func_02027718(int a);
int func_0202771C(int a);
int func_02027720(int a);
int func_0202772C(int a);
int func_02027738(int dummy, int b);
int func_02027740(int dummy, int b);
int func_02027748(void);
int func_0202774C(int a);
int func_02027750(int a);
int func_02027754(int a);
int func_02027758(void);
int func_0202775C(int a);
int func_02027760(int a);
int func_02027764(int a);
int func_02027768(void);
int func_0202776C(int a);
int func_02027770(int a);
int func_02027774(int a);
struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
struct TaskMenu *func_0202784C(struct TaskMenuTmpl *a0, void *a1);
void func_02027858(struct TaskMenu *m);
void func_020278F4(u8 *p);
void func_02027974(struct TaskMenu *p);
u32 func_020279E8(struct TaskMenu *m);
u8 func_02027A04(const u8 *p);
u32 func_02027A08(struct TaskMenu *tm, u32 arg);
extern const u8 d_0209FCF8[];
extern const u8 d_0209FCEC[];
extern char sFile_020A74E0[];








/*
 * Returns the constant 0x53.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275E4.c \
 *       --func func_020275E4 --addr 0x020275E4 --thumb --cc 1.1p1
 */
u32 func_020275E4(void)
{
    return 0x53;
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275E8.c \\
 *       --func func_020275E8 --addr 0x020275E8 --thumb --cc 1.1p1
 */
u32 func_020275E8(void)
{
    return 0x21;
}








/*
 * note: byte lookup in a u8 table; called from ov094 func_02204CC0 (bl at
 *   +0x1EE, 0x02204EAE) with a u8 index.
 */
u8 func_020275EC(int i)
{
    return d_0209FCF8[i];
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275F8.c \\
 *       --func func_020275F8 --addr 0x020275F8 --thumb --cc 1.1p1
 */
u32 func_020275F8(u32 a)
{
    return a + 0x22;
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275FC.c \\
 *       --func func_020275FC --addr 0x020275FC --thumb --cc 1.1p1
 */
u32 func_020275FC(u32 a)
{
    return a + 0x3b;
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027600.c \\
 *       --func func_02027600 --addr 0x02027600 --thumb --cc 1.1p1
 */
u32 func_02027600(u32 a)
{
    return a + 0x3e;
}







/*
 * note: byte lookup in a u8 table; called from ov070, ov131 and ov198.
 */
u8 func_02027604(u8 i)
{
    return d_0209FCEC[i];
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027610.c \\
 *       --func func_02027610 --addr 0x02027610 --thumb --cc 1.1p1
 */
u32 func_02027610(u32 a)
{
    return a + 0x38;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027614.c \\
 *       --func func_02027614 --addr 0x02027614 --thumb --cc 1.1p1
 */
u32 func_02027614(void)
{
    return 0x13;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027618.c \\
 *       --func func_02027618 --addr 0x02027618 --thumb --cc 1.1p1
 */
u32 func_02027618(void)
{
    return 0x14;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202761C.c \\
 *       --func func_0202761C --addr 0x0202761C --thumb --cc 1.1p1
 */
u32 func_0202761C(u32 a)
{
    return a + 0x15;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027620.c \\
 *       --func func_02027620 --addr 0x02027620 --thumb --cc 1.1p1
 */
u32 func_02027620(u32 a)
{
    return a + 0x18;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027624.c \\
 *       --func func_02027624 --addr 0x02027624 --thumb --cc 1.1p1
 */
u32 func_02027624(void)
{
    return 0x1b;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027628.c \\
 *       --func func_02027628 --addr 0x02027628 --thumb --cc 1.1p1
 */
u32 func_02027628(void)
{
    return 0x1c;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202762C.c \\
 *       --func func_0202762C --addr 0x0202762C --thumb --cc 1.1p1
 */
u32 func_0202762C(void)
{
    return 0x1d;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027630.c \\
 *       --func func_02027630 --addr 0x02027630 --thumb --cc 1.1p1
 */
u32 func_02027630(void)
{
    return 0x1e;
}






/*
 *           func_020276A0, func_020276A4, func_020276A8, func_020276AC,
 *           func_020276B0, func_020276B4, func_020276B8, func_020276BC,
 *           func_020276C0
 * beacon_status.c, 0x02027634..0x020276C4: load the beacon status palette,
 * copy its 0x60 colours into the archive's copy and re-base each entry
 * (colour index + base, palette number in the top nibble), then twelve
 * unlabelled 4-byte resource-id getters in groups of four (two constants,
 * two offsets of their argument).
 *
 * What closed the loader after docs/notes/pkt_02027634.c.txt (100 bytes
 * against 96): the palette is a u16[0x60] FIELD at +0x540 of one struct
 * type, and the archive data is that same struct 0xC bytes into the file;
 * with both written as `->pal` the offset 0x540 is one constant kept in r7
 * and the +0xC is added on its own, which is the image.  The re-base is
 * `(pal << 12) + (base + (c & 0xfff))`.
 *
 * Integrator: seed the twelve leaves 0x02027694..0x020276C0 (members).
 */
void func_02027634(void *arc, int id, u32 heap, int base, u32 pal)
{
    struct BeaconGfx *g;
    void *data;
    void *h;
    int i;

    g = (struct BeaconGfx *)func_0204162C(id);
    h = func_02049EF4(arc, 0x1d, 0, &data, heap);
    func_02082D44(((struct BeaconGfx *)((u8 *)data + 0xc))->pal, g->pal, 0xc0);
    func_020307B0(h);
    for (i = 0; i < 0x60; i++)
        g->pal[i] = (pal << 12) + (base + (g->pal[i] & 0xfff));
}






u32 func_02027694(void)
{
    return 0x42;
}






u32 func_02027698(void)
{
    return 0x41;
}






u32 func_0202769C(u32 i)
{
    return i + 0x43;
}






u32 func_020276A0(u32 i)
{
    return i + 0x46;
}






u32 func_020276A4(void)
{
    return 0x49;
}






u32 func_020276A8(void)
{
    return 0x4a;
}






u32 func_020276AC(u32 i)
{
    return i + 0x4b;
}






u32 func_020276B0(u32 i)
{
    return i + 0x4e;
}






u32 func_020276B4(void)
{
    return 0xb;
}






u32 func_020276B8(void)
{
    return 0xc;
}






u32 func_020276BC(u32 i)
{
    return i + 0xd;
}






u32 func_020276C0(u32 i)
{
    return i + 0x10;
}





int func_020276C4(int a0){ int t0, t1; t0 = func_02017E1C((int)a0, (int)0xa0, (int)0); if ((unsigned int)(t0) == (unsigned int)(0)) { return 6; } else { t1 = func_02017E1C((int)((a0 + 0) + 0), (int)0x9d, (int)(0 + 0)); if ((unsigned int)(t1) == (unsigned int)(1)) { return 1; } else { if ((unsigned int)(t1) == (unsigned int)(2)) { return 3; } else { if ((unsigned int)(t1) == (unsigned int)(3)) { return 2; } else { if ((unsigned int)(t1) == (unsigned int)(4)) { return 5; } else { if ((unsigned int)(t1) == (unsigned int)(5)) { return 4; } else { return 8; } } } } } } }




/*
 *           func_02027720, func_0202772C, func_02027738, func_02027740,
 *           func_02027748, func_0202774C, func_02027750, func_02027754,
 *           func_02027758, func_0202775C, func_02027760, func_02027764,
 *           func_02027768, func_0202776C, func_02027770, func_02027774
 *
 * Offset accessors and constants in beacon_status.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02027710.c \
 *       --addr 0x02027710 --thumb --cc 1.1p1
 */
int func_02027710(int a)
{
    return a + 0x51;
}





int func_02027714(int a)
{
    return a + 0x54;
}





int func_02027718(int a)
{
    return a + 0xa6;
}





int func_0202771C(int a)
{
    return a + 0xa9;
}





int func_02027720(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x56;
}





int func_0202772C(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x6f;
}





int func_02027738(int dummy, int b)
{
    return b + 0x89;
}





int func_02027740(int dummy, int b)
{
    return b + 0x8c;
}





int func_02027748(void)
{
    return 0x8f;
}





int func_0202774C(int a)
{
    return a + 0x90;
}





int func_02027750(int a)
{
    return a + 0x93;
}





int func_02027754(int a)
{
    return a + 0x96;
}





int func_02027758(void)
{
    return 0;
}





int func_0202775C(int a)
{
    return a + 2;
}





int func_02027760(int a)
{
    return a + 5;
}





int func_02027764(int a)
{
    return a + 8;
}





int func_02027768(void)
{
    return 0x99;
}





int func_0202776C(int a)
{
    return a + 0x9a;
}





int func_02027770(int a)
{
    return a + 0x9d;
}





int func_02027774(int a)
{
    return a + 0xa0;
}




/*
 * The TaskMenu constructor: allocate the 0x38-byte menu ("app_taskmenu.c",
 * lines 162/168/169), copy the 0x14-byte template in, allocate count*4 and
 * count*12 buffers and copy the template's item table into the second,
 * zero the cursor state, default the two template bytes at +0x12/+0x13 to
 * 13 and 3 when zero, then run func_02027A24 and, unless func_020355C4()
 * says otherwise, func_02027B30 on the current item.
 *
 * Promoted from src/pending (DIFF, 6 bytes out) in wave 12.  The last
 * residue was the scheduling of the +0x12 template load after the three
 * zero stores: the template parameter is NOT const.  With a const pointer
 * mwcc proves the stores into the menu cannot reach the template and
 * hoists the ldrb above them; without it the load stays in source order.
 * The two defaults are unconditional stores of a conditioned value
 * (v = tmpl->unk12; if (v == 0) v = 13; m->tmpl.unk12 = v), not guarded
 * member stores.
 */
struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1)
{
  struct TaskMenu *m;
  m = func_02030734((u16) tmpl->heapId, 0x38, 0, sFile_020A74E0, 162);
  m->tmpl = *tmpl;
  m->arg1 = arg1;
  m->buf1 = func_02030734((u16) m->tmpl.heapId, m->tmpl.count * 4, 0, sFile_020A74E0, 168);
  m->buf2 = func_02030734((u16) m->tmpl.heapId, m->tmpl.count * 12, 0, sFile_020A74E0, 169);
  MIi_CpuCopy16(m->tmpl.unk08, m->buf2, m->tmpl.count * 12);
  m->unk0c = 0;
  m->unk10 = 0;
  m->unk00 = 0;
  m->unk01 = 0;
  m->unk02 = 0;
  m->unk14 = 1U;
  {
    u8 v12 = tmpl->unk12;
    u8 v13;
    if (v12 == 0)
    {
      v12 = 13;
    }
    m->tmpl.unk12 = v12;
    v13 = tmpl->unk13;
    if (v13 == 0)
    {
      v13 = 3;
    }
    m->tmpl.unk13 = v13;
  }
  func_02027a24((struct Obj *)m, arg1);
  if (func_020355c4() == 0)
  {
    func_02027b30((u32)(((void **) m->buf1)[m->unk00]), m->arg1, 1);
  }
  m->unk08 = 1;
  return m;
}





struct TaskMenu *func_0202784C(struct TaskMenuTmpl *a0, void *a1){ struct TaskMenu *t0; t0 = func_02027778(a0, a1); *(int *)&((struct Obj00059 *)((char *)(t0)))->f14 = (int)2; return t0; }





/*
 * Tear down a task menu: drain every queued item of every cell, destroy the
 * cells, drop the shared owner and release the three blocks.
 *
 * The item count at +0x24 is a `u8` and the two loop counters are `u8` too,
 * which is what the `lsls #24 / lsrs #24` pair after each increment says.
 * +0x24 is past the `ldrb` immediate reach of 31, so every read of it costs
 * an `adds r0, #0x24` first
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * The second loop's entry test does not reload the count: it reuses the
 * register the first loop's last bottom-of-loop read left behind, which is
 * why `movs r4, #0 / cmp r0, #0` appears with no load between them.
 *
 * The inner drain is a `while` whose condition is a call, so the condition
 * is emitted twice, once as the entry guard and once as the back edge.
 *
 * EXACT*: the extent runs to 156 bytes because the next function has no
 * label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027858.c \
 *       --func func_02027858 --addr 0x02027858 --cc 1.1p1 --thumb
 */
void func_02027858(struct TaskMenu *m)
{
    void *owner;
    u8 i;
    u8 j;

    owner = (void *)func_02045730(m->buf1[0]);

    for (i = 0; i < m->tmpl.count; i++) {
        while (func_0201C6C4(((struct TaskMenuOwner *)m->arg1)->unk_14,
                             func_02045770(m->buf1[i])) != 0) {
            func_0201C4E4(((struct TaskMenuOwner *)m->arg1)->unk_14);
        }
    }

    for (j = 0; j < m->tmpl.count; j++) {
        func_020456F8(m->buf1[j]);
        func_020452E8(m->buf1[j]);
    }

    func_02041B6C((u32)owner);
    func_020307B0(m->buf1);
    func_020307B0(m->buf2);
    func_020307B0(m);
}





/*
 * app_taskmenu.c: the deselect sweep.  If the menu is in state 1, scan every
 * entry's cell for a hit; a hit clears the sentinel, and only when no hit was
 * found (sentinel still 1) does the second loop tear every cell down and
 * leave state 0.
 *
 * NOTE: the earlier DIFF note read the `adds r7, r4, #0` at +0x18 as a live
 * copy of the loop index, and every spelling chasing that came out 126 bytes.
 * It is not a copy of the index: +0x18 sits BEFORE the loop's back-edge target
 * (0x0202790E), so r7 is set once and never updated.  The assignment in the
 * loop is the constant `sel = 0`, rematerialised off the already-zero r4 per
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 */
void func_020278F4(u8 *p)
{
    u8 i;
    u8 sel;

    if (((struct Obj00104 *)p)->f8 != 1) {
        return;
    }
    sel = 1;
    for (i = 0; i < ((struct Obj00104 *)p)->f24; i++) {
        if (func_0201C6C4((struct PrintSys *)(*(u32 *)(*(u32 *)&((struct Obj00104 *)p)->f34 + 0x14)),
                          (void *)((u32)func_02045770((struct Descriptor *)(*(u32 **)(p + 0x18))[i]))) == 1) {
            sel = 0;
        }
    }
    if (sel != 1) {
        return;
    }
    for (i = 0; i < ((struct Obj00104 *)p)->f24; i++) {
        u32 v = (*(u32 **)(p + 0x18))[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_02041B6C(func_02045730((struct Descriptor *)v));
    }
    ((struct Obj00104 *)p)->f8 = 0;
}





/*
 * field_sound_system.c.  EXACT: all seven relocations resolve.  The calls to
 * func_02027D44 and func_02027E3C carry on class sole-ref/code (each is the
 * only branch anywhere in the image to its target, and each target is exactly
 * a traced Thumb function start); func_02027E3C was additionally filed EXACT
 * in src/matched/ on 2026-09-21, which would carry that site on class matched
 * as well.
 */
void func_02027974(struct TaskMenu *p)
{
    u32 step;
    u16 *q;

    func_020278F4((u8 *)p);
    if (p->unk0c == 0) {
        func_02027D44((struct Menu *)p);
        if (p->unk0c == 0) {
            func_02027E3C((u8 *)p);
        }
    } else {
        step = _u32_div_f(4, p->unk14);
        if ((u8)(_u32_div_f(p->unk01, step) & 1) == 0) {
            func_02027B30((u32)p->buf1[p->unk00], (struct S *)p->arg1, 1);
        } else {
            func_02027B30((u32)p->buf1[p->unk00], (struct S *)p->arg1, 0);
        }
        p->unk01 = (u8)(p->unk01 + 1);
    }
    q = (u16 *)p->arg1;
    func_02027B60(&p->unk02, &p->unk04, (u8)q[0], (u8)q[1]);
}





/*
 * app_taskmenu.c's "does the menu need more than one page" predicate: the
 * per-page capacity is 16 divided by the entry height at +0x14, and the
 * answer is whether the entry count at +1 reaches it.
 *
 * The division is the unsigned runtime helper, so both operands are unsigned
 * and the comparison is `blo`
 * (docs/idioms/runtime-helper-reloc.md).  The 1-returning arm falls through
 * and the 0-returning arm is the branch target, which is the source order
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): the `if` is
 * written `>=`, not `<`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020279E8.c \
 *       --func func_020279E8 --addr 0x020279E8 --cc 1.1p1 --thumb
 */
u32 func_020279E8(struct TaskMenu *m)
{
    if (m->unk01 >= 16 / m->unk14) {
        return 1;
    }
    return 0;
}




u8 func_02027A04(const u8 *p)
{
    return *p;
}


/*
 * The one relocation site's pool word is 0x02027B31, i.e. 0x02027B30 with the
 * Thumb bit set - the header used to declare 0x02077B30, an ARM address, which
 * was a misreading of the word.  Resolved when 0x02027B30 became EXACT.
 */
u32 func_02027A08(struct TaskMenu *tm, u32 arg)
{
    u32 index = tm->unk00;
    void *fn = tm->buf1[index];
    void *ctx = tm->arg1;
    return func_02027B30((u32)fn, (struct S *)ctx, arg);
}
