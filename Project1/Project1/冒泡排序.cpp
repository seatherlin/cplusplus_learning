//template<typename T, typename compare>
//void bsort(const T first, const T last, compare comp)  // ð������
//{
//	while (true)
//	{
//		bool bswap = false;        // ���ֱ����ѽ�����Ԫ�صı�ʶ��true-��������false-δ��������
//		for (auto it = first; ; )
//		{
//			auto left = it;                  // ��ߵ�Ԫ�ء�
//			it++;
//			auto right = it;               // �ұߵ�Ԫ�ء�
//			if (right == last) break;  // ��ʾit1�Ѿ������һ��Ԫ���ˡ�
//
//			//if (*left > *right)             // �����ߵ�Ԫ�ر��ұߴ󣬽������ǵ�ֵ��
//			//if (*left < *right)             // �����ߵ�Ԫ�ر��ұ�С���������ǵ�ֵ��
//			// ����������comp()����true��left����ǰ�棨���򣩣�����right����ǰ�棨���򣩡�
//			if (comp(*left, *right) == true)  continue;
//
//			// ��������Ԫ�ص�ֵ��
//			auto tmp = *right;
//			*right = *left;
//			*left = tmp;
//			bswap = true;        // һ�ֱ����ѽ�����Ԫ�صı�ʶ��
//		}
//
//		if (bswap == false) break;  // �����forѭ���в���������Ԫ�أ�˵��ȫ����Ԫ��������
//	}
//}