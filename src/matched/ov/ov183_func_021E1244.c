/*
 * function: BR_CODEIN_ProfileInitRecordLayout
 * address: 0x021E1244
 * packet: pkt_ov183_021E1244
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave P7 lane V7, pengy share): EXACT in c99 and c. The older DIFF28 draft (see docs/notes) closed with two
 * changes. (1) The row index is a block-local initialised BEFORE the table copy (int row = 0, then the const Table copy):
 * the zero then lives across the copy and the copy takes r5/r3 as in the original. (2) The count row pointer of the last
 * loop is a named State pointer local declared before j (cnt = p + group * 4), which gives j r3
 * and the row pointer r2. Original reads: p[0x2FC] = 1; halfword offsets; a stray store at 0x21A reading row[i - 1] after the
 * copy loop (reproduced as in the listing, probably an off-by-one in the original); no hidden callee arguments.
 * symbols:
 *   d_021E3868 0x021E3868 data a4
 *   BR_CODEIN_ProfileSetActorAnim 0x021E11D0 thumb ov183
 */
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct 
{
  int v[3];
} Row;
typedef struct 
{
  Row row[2];
} Table;
typedef struct 
{
  char pad[0x328];
  int count;
} State;
extern const Table d_021E3868;
extern void BR_CODEIN_ProfileSetActorAnim(char *, int);
void BR_CODEIN_ProfileInitRecordLayout(State *p)
{
  int i;
  int sum;
  int prefix;
  int group;
  int k;
  State *cnt;
  int j;
  u16 truncated;
  char *tmp;
  *((int *) (((char *) p) + 0x2FC)) = 1;
  *((u16 *) (((char *) p) + 0x21C)) = 0;
  sum = *((int *) (((char *) p) + 0x328));
  truncated = sum;
  *((u16 *) (((char *) p) + 0x21E)) = truncated;
  *((u16 *) (((char *) p) + 0x220)) = truncated;
  sum += *((int *) (((char *) p) + 0x32C));
  tmp = ((char *) p) + 0x222;
  truncated = sum;
  *((u16 *) tmp) = truncated;
  *((u16 *) (((char *) p) + 0x224)) = truncated;
  sum = (*((int *) (((char *) p) + 0x330))) + ((int) sum);
  *((u16 *) (((char *) p) + 0x226)) = sum;
  BR_CODEIN_ProfileSetActorAnim((char *) p, 1);
  for (i = 0; i < 3; i++)
    *((int *) (((char *) p) + 0x23C)) += *((int *) ((((u32) p) + (i * 4)) + 0x328));

  {
    int row = 0;
    const Table table = d_021E3868;
    if ((*((int *) (((char *) p) + 0x328))) != 4)
      row = 1;
    for (i = 0; i < 3; i++)
      *((u16 *) ((((u32) p) + (i * 2)) + 0x214)) = table.row[row].v[i];

    *((u16 *) ((((u32) p) + (i * 2)) + 0x214)) = table.row[row].v[i - 1];
    prefix = 0;
    for (group = 0; group < 2; group++)
    {
      prefix += *((int *) ((((u32) p) + (group * 4)) + 0x328));
      *((int *) ((((u32) p) + (group * 28)) + 0x150)) = prefix - 1;
    }

    group = 0;
    j = 0;
    do
    {
      cnt = (State *) (((u32) p) + (group * 4));
      for (k = 0; k < cnt->count; k++)
      {
        *((int *) ((((u32) p) + (j * 28)) + 4)) = group + 1;
        j++;
      }

      group++;
    }
    while (j < (*((int *) (((char *) p) + 0x23C))));
  }
}
