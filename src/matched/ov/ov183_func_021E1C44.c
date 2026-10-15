/*
 * function: BR_CODEIN_ProfileFindRecord
 * address: 0x021E1C44
 * packet: pkt_ov183_021E1C44
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * checks: 1 n/a no calls; 2 matched 1C14 confirms signed index/raw28 stride; 3 enum index DIFF7, unsigned-long count and long index each DIFF4; 4 count/address reuse DIFF4, permuter expands the read-only count field at guard and return; 5 refreshed directory and neighbours; no stack object.
 * matching: re-reading count at guard and return instead of a cached scalar lets the dying offset use r4. No stores or calls can change count during this function.
 * extent: 58 code bytes, alignment padding at021E1C7E..021E1C80; next function starts1C80.
 * retry: 5 one runs, once-only permuter budget300 found expand(n x2) after9 candidates; emitted DIFF4 baseline agrees; winner validated by run6.
 */
int BR_CODEIN_ProfileFindRecord(const char *p, int a)
{
  int i;
  int found;
  unsigned n;
  n = *((const unsigned *) (p + 0x23c));
  found = 0;
  for (i = 0; i < ((int) (*((const unsigned *) (p + 0x23c)))); i++)
  {
    if (a == (*((const int *) ((p + (i * 28)) + 4))))
      found = 1;
    else
      if (found == 1)
      return i - 1;
  }

  return (*((const unsigned *) (p + 0x23c))) - 1;
}
