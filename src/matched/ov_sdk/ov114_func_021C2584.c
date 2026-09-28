/*
 * function: func_021C2584
 * address:  0x021C2584
 * packet:   pkt_ov114_021C2584
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostAddXml (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * symbols:
 *   func_02184234  0x02184234  arm  ov009
 */

struct PostData {
	int type;
	int pad;
	void *xml;
	int rest[3];
};

struct Post {
	void *array;
	unsigned char pad0[8];
	int f0c;
	int f10;
	int f14;
};

extern void func_02184234(void *array, void *newElem);

int func_021C2584(struct Post *_post, void *xml)
{
	struct Post *post;
	struct PostData data;

	post = _post;
	data.type = 3;
	data.xml = xml;
	func_02184234(post->array, &data);
	post->f10 = 1;
	if (post->f0c == 1)
		post->f14 = 1;
	return 1;
}
