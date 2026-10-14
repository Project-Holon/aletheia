/*
 * function: GURU2_MAIN_AddPulseEffectsForMask
 * address: 0x021E14E4
 * packet: pkt_ov137_021E14E4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: base declared before i; initialize i and base before loading count.
 * symbols:
 *   GURU2_MAIN_AddPulseEffect 0x021E14CC thumb ov137
 */
extern void GURU2_MAIN_AddPulseEffect(char *, char *);
typedef struct
{
  int active;
  int a;
  int b;
  int key;
  char rest[0xa4];
} Record;
typedef struct
{
  char pad[0x140];
  Record records[1];
} Block;
void GURU2_MAIN_AddPulseEffectsForMask(const char *p)
{
  int mask = *((int *) (p + 28));
  const Block *base;
  int i;
  int count;
  i = 0;
  base = (const Block *) (p + 0x1a0);
  count = *((int *) (p + 48));
  for (; i < count; i++)
  {
    if ((base->records[i].active != 0) && (mask & (1 << base->records[i].key)))
      GURU2_MAIN_AddPulseEffect((char *) p, (char *) (&base->records[i]));
  }
}
