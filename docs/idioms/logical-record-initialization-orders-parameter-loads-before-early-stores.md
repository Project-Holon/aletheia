# Logical record initialization schedules parameter loads before early stores

summary: when Thumb record initialization has a correct field-store multiset but misplaced entry copies or stack loads, write related fields in logical record order rather than the emitted instruction order.

Found in: src/matched/ov/ov213_func_021BA268.c and src/matched/ov/ov213_func_021BA5A0.c.

With dsi/1.1p1 `-O4,p`, A268 initially wrote `c,zero,owner,a,b,kind,index`, matching the image's store order. That left fifteen differing bytes in the entry register copies and stack loads. A typed destination and a const owner alone were unchanged. Writing `owner,a,b,c,zero,kind,index` instead scheduled all three stack loads before the first store and produced EXACT* (118 bytes plus two alignment bytes). Naming the stack inputs alone had also left the same difference.

A5A0 wrote `owner,other,a,kind,b`; its loop and calls matched after accounting for a four-byte entry shift. Writing `owner,other,kind,a,b` restored both otherwise redundant entry copies and the image's actual `a,kind,b` stores, yielding EXACT132. Changing the owner between pointer, int and const pointer alone had left DIFF115.

The winning assembly still reorders stores. This differs from the typed-struct idiom that preserves source order and complements the acquisition-order result-store idiom: here the values are incoming parameters, not results of earlier calls. Try one evidence-based logical field order within the shared two-variant scheduling budget; do not sweep arbitrary permutations.
