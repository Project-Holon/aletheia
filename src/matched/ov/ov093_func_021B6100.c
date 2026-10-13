/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov093_021B6100
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: the arm9 witnesses src/matched/arm9/CONFIG_GetBattleScene.c and CONFIG_GetBattleStyle.c now exist as EXACT files; the only wildcards left are those two bl targets, so this should lift to EXACT once the integrator regenerates the manifest/labels.
 * lever: the readiness result is held in its own local and the flag
 *   default is written after the call (ready = f(...); flag = 0; if (ready)
 *   flag = 1;); flag = 0 before the call keeps it in r5 (4 bytes), and
 *   if/else or "f(...) != 0" inverts the default (3 bytes).  Also the
 *   allocation is 0x474 bytes (pool word), with the 0x80 bit at p[0x473];
 *   the earlier 0x4b4/0x4b3 spelling cost the pool byte.  Case 2 uses raw
 *   offsets from p (0x450 first, 0x454 second, 0x458 object, 0x45c state)
 *   so the address sums are p + (0x450 + k), as the original computes them.
 * blocker: ARM9 020083AC/C8 no outside witness; primary
 *   asm/arm9/src/001_02007464.s2782..2790, no owner C permitted (the integrator).
 * checks: W82 R11 retry: 1 arities kept from the earlier full check, all 30
 *   call setups byte-correct; 2 B66D4 record twin as before; 3 not needed
 *   after the width-free fix; 4 flag default after the call MATCH, own
 *   ready local MATCH (2/2); 5 idioms reread (spill/flag family).
 * budget W82 R11: f1 baseline 125; f2 raw case-2 offsets 5; f3 own second
 *   flag 5; f4 size 0x474 4; f5 if/else 3; f6 inverted test 3, f7 "!= 0"
 *   3, f8 held result before default 4: three nonshrinking, stopped;
 *   check 4 f9/f10 MATCH. Runs 10; permuter not rerun (earlier run).
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   func_021E8DC4 0x021E8DC4 thumb ov093
 *   func_021E88CC 0x021E88CC thumb ov093
 *   GFL_USE_IsMuteHookActive 0x020057C4 thumb
 *   GFL_USE_SetSleepVolumeHooks 0x020057AC thumb
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   CONFIG_GetBattleScene 0x020083AC thumb
 *   CONFIG_GetBattleStyle 0x020083C8 thumb
 *   func_021EF958 0x021EF958 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021BA82C 0x021BA82C thumb ov093
 *   func_0203F258 0x0203F258 arm
 *   func_021D7840 0x021D7840 thumb ov093
 *   func_021CD6EC 0x021CD6EC thumb ov093
 *   func_021D7F88 0x021D7F88 thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021D4150 0x021D4150 thumb ov093
 *   func_021D804C 0x021D804C thumb ov093
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4230 0x021D4230 thumb ov093
 *   func_021EEA30 0x021EEA30 thumb ov093
 *   func_021B66D4 0x021B66D4 thumb ov093
 *   func_021B9DB8 0x021B9DB8 thumb ov093
 *   func_021BA094 0x021BA094 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *
 * Three-state lifecycle: 6120 allocation/initialization; 633A readiness;
 * 6398 callback completion. State increments and words are unsigned.
 * Original 614C consumes allocator r0 despite own 0203159C's void C;
 * it leaves the allocation result live after its store, so return-use
 * exception retains that exact full-word pointer without callee edits.
 * Original 6132 sets the first flag on the zero-result path, all other
 * paths keep the initial zero. 62B4..62BE copies three u64 words (24 bytes).
 * Callback record matches own B66D4's four physical words; indirect call
 * casts express this caller's two supplied inputs and tested r0 result.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Lcg64
{
  u64 x;
  u64 mul;
  u64 add;
};
struct FlagByte
{
  u8 a0 : 1;
  u8 a1 : 1;
  u8 a2 : 1;
  u8 a3 : 1;
  u8 a4 : 1;
  u8 a5 : 1;
  u8 a6 : 1;
  u8 a7 : 1;
};
struct Callback
{
  void (*first)(void);
  u32 second;
  u8 *object;
  u32 state;
};
typedef int (*CallbackFn)(u32 *, u8 *);
struct Obj0203159C
{
  u32 pad00[5];
  void *buffer;
};
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082A7C(u32, void *, u32);
struct S;
extern void func_021E8DC4(unsigned short heap);
extern void func_021E88CC(void);
extern int GFL_USE_IsMuteHookActive(void);
extern void GFL_USE_SetSleepVolumeHooks(void);
extern u32 CONFIG_GetTextSpeed(int);
extern u32 CONFIG_GetBattleScene(void *);
extern u32 CONFIG_GetBattleStyle(void *);
extern void *func_021EF958(u32);
extern void func_021B93E0(char *, u32, u32);
extern void func_021BA82C(char *);
extern void func_0203F258(struct Lcg64 *);
extern void func_021D7840(struct Lcg64 *, u32);
extern void func_021CD6EC(void);
extern u32 func_021D7F88(u8 *);
extern void func_021D8230(u8 *p);
extern void func_021D4150(void *, u16, u16);
extern void func_021D804C(u32);
extern int func_021D4270(void);
extern int func_021D4230(void);
extern void func_021EEA30(int v);
extern void func_021B66D4(struct Callback *, u8 *, u8 *);
extern void func_021B9DB8(char *p);
extern void func_021BA094(struct S *p);
extern void func_021BA1B4(char **p, int i);
int func_021B6100(struct Obj0203159C *owner, u32 *state, u8 *q, u8 *p)
{
  u32 flag;
  u32 i;
  u32 ready;
  int done;
  switch (*state)
  {
    case 0:
      func_0203064C(1, 0x12, 0x20000);
      func_0203064C(1, 0x14, 0x8000);
      func_0203064C(1, 0x13, 0xab100);
      p = func_0203159C(owner, 0x474, 0x12);
      func_02082A7C(0, p, 0x474);
      func_021E8DC4(0x13);
      func_021E88CC();
      if (!GFL_USE_IsMuteHookActive())
      {
        GFL_USE_SetSleepVolumeHooks();
        p[0x473] |= 0x80;
      }
      *((u16 *) (p + 0x468)) = 0x12;
      *((u8 **) p) = q;
      q[0x90] = 6;
      *((u32 *) (p + 0xc0)) = *((u32 *) ((*((u8 **) p)) + 0x34));
      *((u16 *) (p + 0x440)) = *((u16 *) ((*((u8 **) p)) + 0x74));
      *((u16 *) (p + 0x442)) = *((u16 *) ((*((u8 **) p)) + 0x76));
      ((struct FlagByte *) (p + 0x473))->a3 = 0;
      ((struct FlagByte *) (p + 0x473))->a4 = 0;
      ((struct FlagByte *) (p + 0x473))->a0 = 0;
      ((struct FlagByte *) (p + 0x473))->a1 = 0;
      ((struct FlagByte *) (p + 0x473))->a5 = 0;
      ((struct FlagByte *) (p + 0x473))->a6 = 0;
      p[0x471] = 0;
      *((u32 *) (p + 0x464)) = 0;
      flag = 0;
      *((u32 *) (p + 4)) = 0;
      *((u32 *) (p + 0x444)) = 7;
      *((u32 *) (p + 0x43c)) = CONFIG_GetTextSpeed(*((int *) ((*((u8 **) p)) + 0x5c)));
      if (CONFIG_GetBattleScene(*((void **) (q + 0x5c))) == 0)
        flag = 1;
      ((struct FlagByte *) (p + 0x473))->a2 = (u8) flag;
      *((void **) (p + 0x2bc)) = func_021EF958(*((u16 *) (p + 0x468)));
      func_021B93E0(((char *) p) + 0xc8, (u32) p, 0);
      func_021B93E0(((char *) p) + 0x1b0, (u32) p, 1);
      func_021BA82C(*((char **) p));
      *((u32 *) (p + 0x2c0)) = 0;
      *((u32 *) (p + 0x2c4)) = 0;
      if ((*((u8 **) p))[0x23] == 0)
        func_0203F258((struct Lcg64 *) (p + 0x3f0));
      else
        *((struct Lcg64 *) (p + 0x3f0)) = *((struct Lcg64 *) (q + 0x9c));
      func_021D7840((struct Lcg64 *) (p + 0x3f0), *((u16 *) (p + 0x468)));
      func_021CD6EC();
      *((u32 *) (p + 0x430)) = func_021D7F88(q);
      *((u32 *) (p + 0x434)) = 0;
      *((u32 *) (p + 0x438)) = 0;
      if ((*((u8 **) p))[0x23] == 0)
      {
        for (i = 0; i < 4; i++)
          (*((u8 **) p))[0x44 + i] = 0;
      }
      func_021D8230(p + 0x448);
      ready = CONFIG_GetBattleStyle(*((void **) (q + 0x5c)));
      flag = 0;
      if (ready != 0)
        flag = 1;
      p[0x46f] = flag;
      func_021D4150(*((void **) (q + 0x1c)), *((u16 *) (q + 0x84)), 0x14);
      func_021D804C(0x12);
      (*state)++;
      break;

    case 1:
      if (((*((void **) ((*((u8 **) p)) + 0x1c))) != 0) && func_021D4270())
      {
        ((struct FlagByte *) (p + 0x473))->a0 = 1;
        ((struct FlagByte *) (p + 0x473))->a1 = 1;
        return 1;
      }
      if (func_021D4230())
      {
        func_021EEA30((*((u8 **) p))[0x20]);
        func_021B66D4((struct Callback *) (p + 0x450), p, *((u8 **) p));
        *((u32 *) (p + 0x460)) = 0;
        func_021B9DB8((char *)p);
        func_021BA094((struct S *)p);
        (*state)++;
      }
      break;

    case 2:
      if (*(void **)(p + 0x450) != 0)
      {
        if (((CallbackFn) *(void **)(p + 0x450))((u32 *)(p + 0x45c), *(u8 **)(p + 0x458)))
        {
          *(u32 *)(p + 0x450) = 0;
          *(u32 *)(p + 0x45c) = 0;
        }
        done = 0;
      }
      else if (*(u32 *)(p + 0x454) != 0)
      {
        if (((CallbackFn) *(u32 *)(p + 0x454))((u32 *)(p + 0x45c), *(u8 **)(p + 0x458)))
        {
          *(u32 *)(p + 0x454) = 0;
          done = 1;
        }
        else
          done = 0;
      }
      else
        done = 1;
      if (done != 0)
      {
        if (((struct FlagByte *) (p + 0x473))->a0 != 0)
        {
          ((struct FlagByte *) (p + 0x473))->a1 = 1;
          return 1;
        }
        if ((*((u32 *) (*((u8 **) p)))) != 4)
          func_021BA1B4((char **)p, 4);
        return 1;
      }
      break;
  }

  return 0;
}
