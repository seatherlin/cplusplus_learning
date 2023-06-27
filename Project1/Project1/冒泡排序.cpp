//template<typename T, typename compare>
//void bsort(const T first, const T last, compare comp)  // 冒泡排序。
//{
//	while (true)
//	{
//		bool bswap = false;        // 本轮遍历已交换过元素的标识，true-交换过，false-未交换过。
//		for (auto it = first; ; )
//		{
//			auto left = it;                  // 左边的元素。
//			it++;
//			auto right = it;               // 右边的元素。
//			if (right == last) break;  // 表示it1已经是最后一个元素了。
//
//			//if (*left > *right)             // 如果左边的元素比右边大，交换它们的值。
//			//if (*left < *right)             // 如果左边的元素比右边小，交换它们的值。
//			// 排序规则：如果comp()返回true，left排在前面（升序），否则right排在前面（降序）。
//			if (comp(*left, *right) == true)  continue;
//
//			// 交换两个元素的值。
//			auto tmp = *right;
//			*right = *left;
//			*left = tmp;
//			bswap = true;        // 一轮遍历已交换过元素的标识。
//		}
//
//		if (bswap == false) break;  // 如果在for循环中不曾交换过元素，说明全部的元素已有序。
//	}
//}