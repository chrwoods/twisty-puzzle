// note for display maps:
// 0: nothing
// 1: up face
// 2: left face
// 3: front face
// 4: right face
// 5: back face
// 6: down face
// 7-24: one of the faces except rotated by the multiple of 6 added to it
// i.e. 17 is 5 + (6 * 2), so it's the back face rotated twice
//
// rotation is supported so that if faces are moved around
// they can be rotated so the cube still has a visual "connection"
// AKA the faces will still connect to eachothers so that
// rotations will visually make sense

const short map_1[3][4] = {{0, 1, 0, 0},
			   {2, 3, 4, 5},
			   {0, 6, 0, 0}};
