/*
 * function: CTVT_ADPCM_DecodeSample
 * address: 0x021B6B68
 * packet: pkt_ov172_021B6B68
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare step,value,index,delta; loads remain value,index,step.
 * symbols:
 *   gImaStepTable 0x021C4D20 data a4
 *   gImaIndexTable 0x021C4D10 data a1
 */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern const int gImaStepTable[];
extern const s8 gImaIndexTable[];
s16 CTVT_ADPCM_DecodeSample(u8 code, const char *p)
{
  int step;
  int value;
  int index;
  int delta;
  value = *((s16 *) p);
  index = *((s8 *) (p + 2));
  step = gImaStepTable[index];
  delta = step >> 3;
  if (code & 4)
    delta += step;
  if (code & 2)
    delta += step >> 1;
  if (code & 1)
    delta += step >> 2;
  if (code & 8)
  {
    value -= delta;
    if (value < (-32767))
      value = -32767;
  }
  else
  {
    value += delta;
    if (value > 32767)
      value = 32767;
  }
  index += gImaIndexTable[code];
  if (index < 0)
    index = 0;
  else
    if (index > 88)
    index = 88;
  *((s16 *) p) = (s16) value;
  *((s8 *) (p + 2)) = index;
  return (s16) value;
}
