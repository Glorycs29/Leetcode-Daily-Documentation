class Solution {
    public:
        bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
                int xDist = abs(sx - fx);
                        int yDist = abs(sy - fy);

                                if (xDist == 0 && yDist == 0) {
                                            return t != 1;
                                                    }

                                                            return xDist <= t && yDist <= t;
                                                                }
                                                                };


