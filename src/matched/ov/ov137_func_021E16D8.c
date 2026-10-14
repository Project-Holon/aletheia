/*
 * function: GURU2_MAIN_AreAllOthersReady
 * address: 0x021E16D8
 * packet: pkt_ov137_021E16D8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Lever: initialise count before bound, then carry bound through a plain copy bound_ after x is loaded.
 * Direct bound use left a four-byte zero/subtraction scheduling swap; bounded permuter found the copy spelling.
 * trailing: Two zero alignment bytes.
 */
int GURU2_MAIN_AreAllOthersReady(const char *p)
{
  unsigned int count;
  int bound;
  unsigned int x;
  int bound_;
  count = 0;
  bound = (*((int *) ((*((char **) (p + 0xd8))) + 8))) - 1;
  x = *((unsigned short *) ((*((char **) (p + 0xdc))) + 0x42));
  bound_ = bound;
  while (x)
  {
    count += x & 1;
    x >>= 1;
  }

  return ((int) count) >= bound_;
}
