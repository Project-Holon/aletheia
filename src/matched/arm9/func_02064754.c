/*
 * function: NNS_G2dInitMCAnimation
 * address:  0x02064754
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dGetMCBankNumCellAnimRequired  0x02064648  arm
 *   NNS_G2dGetMCBankNumNodesRequired  0x020648E0  arm
 *   NNS_G2dGetAnimSequenceByIdx  0x020627D8  arm
 *   NNS_G2dInitCellAnimation  0x0206428C  arm
 *   NNSi_G2dInitMCNode  0x02064178  arm
 *   NNS_G2dInitAnimCtrl  0x02062F38  arm
 *   NNSi_G2dSrtcInitControl  0x02064140  arm
 *
 * Build a multi-cell animation's cell array (docs/families/cluster_020640DC.h,
 * section 3): kind == 1 is the flat 0x5c-stride array sized by
 * NNS_G2dGetMCBankNumCellAnimRequired(bank), anything else the two-level shape of
 * NNS_G2dGetMCBankNumNodesRequired(bank) 0x28-byte group headers followed by 0x58-stride cells.
 *
 * Three things closed it after docs/notes/pkt_02064754.c.txt stalled at 70
 * out:
 *   - DATA FLOW.  The NMCR bank handed to both sizing calls is the FIFTH
 *     argument (loaded from [sp,#0x28] into r0 before the kind test and
 *     respilled to its own slot), and the second argument is the cell
 *     buffer stored at +0x40 and used as the group-header base.  The note's
 *     body passed the second argument to NNS_G2dGetMCBankNumNodesRequired; with the flow
 *     corrected no `volatile` is needed for the respill.
 *   - Arm 2 runs the four-call tail TWICE (it falls into the shared copy),
 *     so the tail is written in the arm and again after the if.
 *   - The count and index are declared PER ARM (u16 n, i inside each
 *     block); function-scope n / i are 18 out (a register swap in both
 *     loops), a separate j for arm 2 is 4 bytes short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dInitMCAnimation.c \
 *       --func NNS_G2dInitMCAnimation --addr 0x02064754 --arm --cc ../2.0/sp2
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct AnimBank;
struct AnimSequence;
struct MultiCellBank;
extern u16 NNS_G2dGetMCBankNumCellAnimRequired(struct MultiCellBank *bank);
extern u16 NNS_G2dGetMCBankNumNodesRequired(struct MultiCellBank *bank);
extern struct AnimSequence *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx);
extern void NNS_G2dInitCellAnimation(char *self, int a1, char *c);
extern void NNSi_G2dInitMCNode(char *o, u32 a);
extern int NNS_G2dInitAnimCtrl(int a0);
struct O02064140;
extern void NNSi_G2dSrtcInitControl(struct O02064140 *o, u32 a);
void NNS_G2dInitMCAnimation(char *o, char *buf, void *set, int a3, void *bank, int kind)
{
  if (kind == 1)
  {
    char *cells;
    u16 n;
    u16 i;
    *((int *) (o + 0x3c)) = 1;
    *((void **) (o + 0x38)) = set;
    *((char **) (o + 0x40)) = buf;
    n = NNS_G2dGetMCBankNumCellAnimRequired(bank);
    cells = *((char **) (o + 0x40));
    for (i = 0; i < n; i++)
    {
      char *cell = cells + i * 0x5c;
      NNS_G2dInitCellAnimation(cell, (int)NNS_G2dGetAnimSequenceByIdx(set, 0), (char *)a3);
      *((int *) (cell + 0x58)) = 1;
    }
  }
  else
  {
    char *base;
    u16 n;
    u16 i;
    n = NNS_G2dGetMCBankNumNodesRequired(bank);
    base = buf + n * 0x28;
    *((int *) (o + 0x3c)) = 0;
    *((int *) (o + 0x34)) = 0;
    *((void **) (o + 0x38)) = set;
    *((char **) (o + 0x40)) = buf;
    for (i = 0; i < n; i++)
    {
      char *hdr = buf + i * 0x28;
      char *cell;
      NNSi_G2dInitMCNode(hdr, 1);
      cell = base + i * 0x58;
      *((char **) hdr) = cell;
      NNS_G2dInitCellAnimation(cell, (int)NNS_G2dGetAnimSequenceByIdx(set, 0), (char *)a3);
    }
    NNS_G2dInitAnimCtrl((int)o);
    *((void **) (o + 0x44)) = bank;
    NNSi_G2dSrtcInitControl((struct O02064140 *)(o + 0x48), 1);
    *((u16 *) (o + 0x30)) = 0;
  }
  NNS_G2dInitAnimCtrl((int)o);
  *((void **) (o + 0x44)) = bank;
  NNSi_G2dSrtcInitControl((struct O02064140 *)(o + 0x48), 1);
  *((u16 *) (o + 0x30)) = 0;
}
