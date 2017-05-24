#ifndef __TREE_H__
#define __TREE_H__

namespace tree{

    class Node{
        public:
            double val;
            Node *Left;
            Node *Right;

            //contructor
            Node();
            Node(double value);
            Node(Node *begin);
            bool Search(const double val);
            bool IsBigger(const double val);
            bool IsSmaller(const double val);
            void HowMany(const double val, int *counter);

    };
}

#endif