/*
 * file:     unit_0217FC68.c
 * function: B64InitEncodeStream
 * address:  0x0217FC68
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Initialises a base64 encode stream: stores input pointer, input length
 * and the current position (home: gsplatformutil.o, just before B64EncodeStream).
 */

void B64InitEncodeStream(int *stream, int input, int inputLength, int position)
{
    stream[0] = input;
    stream[1] = inputLength;
    stream[2] = position;
}
