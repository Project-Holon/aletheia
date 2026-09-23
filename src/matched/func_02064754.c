/*
 * function: func_02064754
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
 *   func_02064648  0x02064648  arm
 *   func_020648E0  0x020648E0  arm
 *   func_020627D8  0x020627D8  arm
 *   func_0206428C  0x0206428C  arm
 *   func_02064178  0x02064178  arm
 *   func_02062F38  0x02062F38  arm
 *   func_02064140  0x02064140  arm
 *
 * Build a multi-cell animation's cell array (docs/families/cluster_020640DC.h,
 * section 3): kind == 1 is the flat 0x5c-stride array sized by
 * func_02064648(bank), anything else the two-level shape of
 * func_020648E0(bank) 0x28-byte group headers followed by 0x58-stride cells.
 *
 * Three things closed it after docs/notes/pkt_02064754.c.txt stalled at 70
 * out:
 *   - DATA FLOW.  The NMCR bank handed to both sizing calls is the FIFTH
 *     argument (loaded from [sp,#0x28] into r0 before the kind test and
 *     respilled to its own slot), and the second argument is the cell
 *     buffer stored at +0x40 and used as the group-header base.  The note's
 *     body passed the second argument to func_020648E0; with the flow
 *     corrected no `volatile` is needed for the respill.
 *   - Arm 2 runs the four-call tail TWICE (it falls into the shared copy),
 *     so the tail is written in the arm and again after the if.
 *   - The count and index are declared PER ARM (u16 n, i inside each
 *     block); function-scope n / i are 18 out (a register swap in both
 *     loops), a separate j for arm 2 is 4 bytes short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064754.c \
 *       --func func_02064754 --addr 0x02064754 --arm --cc ../2.0/sp2
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_02064648(void *bank);
extern u16 func_020648E0(void *bank);
extern void *func_020627D8(void *set, u32 idx);
extern void func_0206428C(char *cell, void *row, int a2);
extern void func_02064178(char *hdr, int v);
extern void func_02062F38(char *self);
extern void func_02064140(char *p, int v);
void func_02064754(char *o, char *buf, void *set, int a3, void *bank, int kind)
{
  if (kind == 1)
  {
    char *cells;
    u16 n;
    u16 i;
    *((int *) (o + 0x3c)) = 1;
    *((void **) (o + 0x38)) = set;
    *((char **) (o + 0x40)) = buf;
    n = func_02064648(bank);
    cells = *((char **) (o + 0x40));
    for (i = 0; i < n; i++)
    {
      char *cell = cells + i * 0x5c;
      func_0206428C(cell, func_020627D8(set, 0), a3);
      *((int *) (cell + 0x58)) = 1;
    }
  }
  else
  {
    char *base;
    u16 n;
    u16 i;
    n = func_020648E0(bank);
    base = buf + n * 0x28;
    *((int *) (o + 0x3c)) = 0;
    *((int *) (o + 0x34)) = 0;
    *((void **) (o + 0x38)) = set;
    *((char **) (o + 0x40)) = buf;
    for (i = 0; i < n; i++)
    {
      char *hdr = buf + i * 0x28;
      char *cell;
      func_02064178(hdr, 1);
      cell = base + i * 0x58;
      *((char **) hdr) = cell;
      func_0206428C(cell, func_020627D8(set, 0), a3);
    }
    func_02062F38(o);
    *((void **) (o + 0x44)) = bank;
    func_02064140(o + 0x48, 1);
    *((u16 *) (o + 0x30)) = 0;
  }
  func_02062F38(o);
  *((void **) (o + 0x44)) = bank;
  func_02064140(o + 0x48, 1);
  *((u16 *) (o + 0x30)) = 0;
}
