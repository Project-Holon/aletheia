/*
 * function: func_0216F770
 * address:  0x0216F770
 * packet:   pkt_ov009_0216F770
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  reconstruction is complete and the right size (868), but the
 *           whole body is emitted through a different callee-saved register
 *           map, so almost every instruction differs while the control flow,
 *           the 9-byte basicFields prefix (8,0xa,0x32..0x38), the
 *           stGameMatchKeys append loop, the 0x61c switch (cases 2 / 3,4,0x16
 *           / 9,10,11 / 12 / default) and the ServerBrowserLimitUpdateA retry
 *           loop all trace to the original.  The source-level tell that is
 *           still missing is the `6 + 3` numBasicFields pair: the original
 *           keeps 6 live in sl and emits `add r7,sl,#3`, i.e. 6 is a real
 *           local reused as the retry counter, not a folded literal.  Format
 *           strings are declared as extern data symbols (d_021A20xx) rather
 *           than literals; they resolve.  permuter.py anneal 350 only closes
 *           the size with scaffolding (pad/pad1, volatile, if(1)); the clean
 *           form is 852 bytes.
 *
 * sdk:      DWCi_SBUpdateAsync (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_0216FAD4  0x0216FAD4  arm  ov009
 *   func_0219F00C  0x0219F00C  arm  ov009
 *   func_0219EED4  0x0219EED4  arm  ov009
 *   OS_SNPrintf    0x02084F80  arm
 *   OS_GetTick     0x020870D0  arm
 *   stGameMatchKeys          0x021AAA40  data
 *   s_anybodyServerSearchRatio 0x021A203C  data
 *   s_bInNNThink             0x021AAA20  data
 *   d_021A2090     0x021A2090  data
 *   d_021A209C     0x021A209C  data
 *   d_021A20A4     0x021A20A4  data
 *   d_021A20AC     0x021A20AC  data
 *   d_021A20D4     0x021A20D4  data
 *   d_021A20E0     0x021A20E0  data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
extern char *func_02175F3C(void);
extern u32 func_021685CC(u32 max);
extern int func_0216FAD4(char *filter, int profileID, u8 numEntry, u8 matchType, u8 hostState);
extern void func_0219F00C(void *sb);
extern int func_0219EED4(void *sb, int async, int disconnectOnComplete, u8 *basicFields, int numBasicFields, char *serverFilter, int maxServers);
extern int OS_SNPrintf(char *dst, u32 len, char *fmt, ...);
extern u64 OS_GetTick(void);
extern u8 stGameMatchKeys[];
extern int s_anybodyServerSearchRatio;
extern int s_bInNNThink;
extern char d_021A2090[];
extern char d_021A209C[];
extern char d_021A20A4[];
extern char d_021A20AC[];
extern char d_021A20D4[];
extern char d_021A20E0[];
static int func_0216F770(volatile int profileID)
{
  char filter[511];
  u8 basicFields[204];
  int sbError;
  int sbBlock;
  u8 searchHostType;
  int i;
  int n;
  int numBasicFields;
  int len;
  u8 pad;
  u16 pad1;
  sbBlock = 8;
  basicFields[0] = 8;
  if (1)
  {
    basicFields[1] = 0xa;
    basicFields[2] = 0x32;
  }
  basicFields[3] = 0x33;
  basicFields[4] = 0x34;
  basicFields[5] = 0x35;
  basicFields[6] = 0x36;
  basicFields[7] = 0x37;
  basicFields[8] = 0x38;
  searchHostType = profileID;
  n = 6;
  numBasicFields = n + 3;
  i = 0;
  if (((*((u8 *) (func_02175F3C() + 0x15))) == 0) || ((*((u8 *) (func_02175F3C() + 0x15))) == 1))
  {
    for (i = 0; i < 0x9a; i++)
    {
      u8 v = stGameMatchKeys[i * 0xc];
      if (v != 0)
        basicFields[numBasicFields++] = v;
    }

  }
  switch (*((int *) (func_02175F3C() + 0x61c)))
  {
    case 2:
      if (s_anybodyServerSearchRatio == (-1))
    {
      searchHostType = ((*((u8 *) (func_02175F3C() + 0x7a8))) == 1) ? (2) : (3);
      *((u8 *) (func_02175F3C() + 0x7a8)) = 0;
    }
    else
      if (s_anybodyServerSearchRatio == 0)
    {
      searchHostType = ((*((u8 *) (func_02175F3C() + 0x7a8))) != 0) ? (2) : (0);
      *((u8 *) (func_02175F3C() + 0x7a8)) ^= 1;
    }
    else
    {
      searchHostType = (func_021685CC(100) < ((u32) s_anybodyServerSearchRatio)) ? (2) : (0);
    }
      len = func_0216FAD4(filter, *((int *) (func_02175F3C() + 0x678)), *((u8 *) (func_02175F3C() + 0x17)), *((u8 *) (func_02175F3C() + 0x15)), searchHostType);
      if ((*((int *) (((char *) (&s_bInNNThink)) + 0xc))) != 0)
    {
      OS_SNPrintf(filter + len, 0x1ff - len, d_021A2090);
      filter[0x1fe] = 0;
    }
      *((int *) (func_02175F3C() + 0x7ac)) = (*((int *) (func_02175F3C() + 0x7ac))) + 1;
      break;

    case 3:

    case 4:

    case 0x16:
      OS_SNPrintf(filter, 0x1ff, d_021A209C, d_021A20A4, searchHostType);
      *((int *) (func_02175F3C() + 0x67c)) = searchHostType;
      break;

    case 9:

    case 10:

    case 11:
      OS_SNPrintf(filter, 0x1ff, d_021A20E0, d_021A20AC, searchHostType);
      sbBlock = 0;
      break;

    case 12:
      OS_SNPrintf(filter, 0x1ff, d_021A20AC, d_021A20D4, *((int *) (func_02175F3C() + 0x790)), d_021A20E0, 2, d_021A20A4, *((int *) (func_02175F3C() + 0x678)));
      break;

    default:
      break;

  }

  func_0219F00C((void *) (*((int *) (func_02175F3C() + 0x5e0))));
  n = 0;
  do
  {
    sbError = func_0219EED4((void *) (*((int *) (func_02175F3C() + 0x5e0))), sbBlock, 0, basicFields, numBasicFields, filter, ((*((int *) (func_02175F3C() + 0x61c))) == 0x16) ? (1) : (6));
    if (sbError == 0)
      break;
    if (sbError != 2)
      break;
    n++;
  }
  while (n < 1);
  if (sbError == 0)
  {
    *((u64 *) (func_02175F3C() + 0x5f0)) = OS_GetTick() + 0xefb5f7;
  }
  return sbError;
}


