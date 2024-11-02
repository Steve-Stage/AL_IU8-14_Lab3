#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>

#define min(a, b) (((a) <= (b)) ? (a) : (b))
#define max(a, b) (((a) >= (b)) ? (a) : (b))

template <class T>
std::vector<T> generate_random_vector(std::size_t, T, T);

void task1()
{
	int n, m1, m2, a;
	std::cout << "Enter size of array, minimal and maximal element values, value A (n >= 1, delimited with spaces): ";
	std::cin >> n >> m1 >> m2 >> a;
	std::vector<int> v = generate_random_vector<int>(max(n, 1), m1, m2);
	std::cout << "Original array: { " << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << "; " << v[i];
	}
	std::cout << " }" << std::endl;
	int fe = v[0];
	std::cout << "Result array: { " << double(fe * 2 - a) / double(fe);
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << "; " << double(v[i] * 2 - a) / double(fe);
	}
	std::cout << " }" << std::endl;
	return;
}

void task2()
{
	int n, m1, m2, k1, k2, s1, s2;
	std::cout << "Enter size of array, minimal and maximal element values (n >= 6, delimited with spaces): ";
	std::cin >> n >> m1 >> m2;
	std::vector<int> v = generate_random_vector<int>(max(n, 6), m1, m2);
	std::cout << "Enter k1, k2 (k1 < k2, delimited with spaces): ";
	std::cin >> k1 >> k2;
	std::cout << "Enter s1, s2 (s1 < s2, delimited with spaces): ";
	std::cin >> s1 >> s2;
	int r1 = 0, r2 = 0, r3 = 0, rk = 0;
	double ra = 0.0, rs = 0.0;
	for (int i = 0; i < v.size(); i++)
	{
		r1 += v[i];
		r2 += v[i] * v[i];
		r3 += v[i] * int(i < 6);
		rk += v[i] * int(i >= (k1 - 1)) * int(i <= (k2 - 1));
		rs += double(v[i] * int(i >= (s1 - 1)) * int(i <= (s2 - 1)));
	}
	ra = double(r1) / double(v.size());
	rs /= double(s2 - s1 + 1);
	std::cout << "Original array: { " << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << "; " << v[i];
	}
	std::cout << " }" << std::endl;
	std::cout << "Sum of all elements: " << r1 << std::endl;
	std::cout << "Sum of squares of every element: " << r2 << std::endl;
	std::cout << "Sum of first 6 elements: " << r3 << std::endl;
	std::cout << "Sum of [k1; k2] = [" << k1 << "; " << k2 << "] elements: " << rk << std::endl;
	std::cout << "Average of all elements: " << ra << std::endl;
	std::cout << "Average of [s1; s2] = [" << s1 << "; " << s2 << "] elements: " << rs << std::endl;
	return;
}

void task3()
{
	int m1, m2;
	std::cout << "Enter minimal and maximal element values (delimited with spaces): ";
	std::cin >> m1 >> m2;
	std::vector<int> v = generate_random_vector<int>(20, m1, m2);
	std::cout << "Original array: { " << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << "; " << v[i];
	}
	std::cout << " }" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		int tmp = v[i];
		v[i] = v[v.size() - (3 - i)];
		v[v.size() - (3 - i)] = tmp;
	}
	std::cout << "Result array: { " << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << "; " << v[i];
	}
	std::cout << " }" << std::endl;
	return;
}

void task4()
{
	int n, m1, m2, k1, k2, s1, s2;
	std::cout << "Enter size of array, minimal and maximal element values (n >= 1, delimited with spaces): ";
	std::cin >> n >> m1 >> m2;
	std::vector<int> v = generate_random_vector<int>(max(n, 1), m1, m2);
	std::cout << "Original array: { " << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << "; " << v[i];
	}
	std::cout << " }" << std::endl;
	std::vector<int> r;
	r.reserve(max(n, 1));
	std::vector<int>::iterator i1;
	std::vector<int>::reverse_iterator i2;
	for (i1 = v.begin(); i1 != v.end(); i1++)
	{
		if (*i1 < 0)
			break;
	}
	for (i2 = v.rbegin(); i2 != v.rend(); i2++)
	{
		if (!(*i2 % 2))
			break;
	}
	for (auto i = v.begin(); i != v.end(); i++)
	{
		if (i == i1 || std::next(i) == i2.base())
			continue;
		r.push_back(*i);
	}
	std::cout << "Result array: { " << r[0];
	for (int i = 1; i < r.size(); i++)
	{
		std::cout << "; " << r[i];
	}
	std::cout << " }" << std::endl;
	return;
}

void task5()
{
	std::string s;
	std::cout << "Enter name of city: ";
	std::cin >> s;
	std::cout << "Amount of symbols in city \"" << s << "\" is " << ((s.size() % 2) ? ("odd") : ("even"))
			  << " and is equal to " << s.size() << std::endl;
	return;
}

void task6()
{
	std::string s1, s2;
	std::cout << "Enter first surname: ";
	std::cin >> s1;
	std::cout << "Enter second surname: ";
	std::cin >> s2;
	if (s1.size() == s2.size())
		std::cout << "Surnames have equal length" << std::endl;
	else
		std::cout << ((s1.size() > s2.size()) ? ("First") : ("Second")) << " surname is longer" << std::endl;
	return;
}

void task7()
{
	std::string s1, s2, s3;
	std::cout << "Enter first city name: ";
	std::cin >> s1;
	std::cout << "Enter second city name: ";
	std::cin >> s2;
	std::cout << "Enter third city name: ";
	std::cin >> s3;
	if (s1.size() == s2.size() && s2.size() == s3.size())
		std::cout << "All 3 cities names have equal length" << std::endl;
	else
	{
		int i1 = (s1.size() >= max(s2.size(), s3.size())) - (s1.size() < min(s2.size(), s3.size()));
		int i2 = (s2.size() >= max(s1.size(), s3.size())) - (s2.size() < min(s1.size(), s3.size()));
		int i3 = (s3.size() >= max(s1.size(), s2.size())) - (s3.size() < min(s1.size(), s2.size()));
		if (!(i1 + i2 + i3))
		{
			std::cout << "Longer city name is \"" << ((i1 == 1) ? (s1) : ((i2 == 1) ? (s2) : (s3))) << '\"'
					  << std::endl;
			std::cout << "Shorter city name is \"" << ((i1 == -1) ? (s1) : ((i2 == -1) ? (s2) : (s3))) << '\"';
		}
		else
		{
			if (i1 == i2 && i1 == 1)
			{
				std::cout << "Longer city names are \"" << s1 << "\" and \"" << s2 << '\"' << std::endl;
				std::cout << "Shorter city name is \"" << s3 << '\"';
			}
			else if (i1 == i3 && i1 == 1)
			{
				std::cout << "Longer city names are \"" << s1 << "\" and \"" << s3 << '\"' << std::endl;
				std::cout << "Shorter city name is \"" << s2 << '\"';
			}
			else if (i2 == i3 && i2 == 1)
			{
				std::cout << "Longer city names are \"" << s2 << "\" and \"" << s3 << '\"' << std::endl;
				std::cout << "Shorter city name is \"" << s1 << '\"';
			}
			else
			{
				int ix = -2;
				std::cout << "Longer city name is \""
						  << ((i1 == 1) ? (ix = 1, s1) : ((i2 == 1) ? (ix = 2, s2) : (ix = 3, s3))) << '\"'
						  << std::endl;
				std::cout << "Shorter city names are \""
						  << ((ix == 1) ? (s2 + "\" and \"" + s3)
										: ((ix == 2) ? (s1 + "\" and \"" + s3) : (s1 + "\" and \"" + s2)))
						  << '\"';
			}
		}
	}
	std::cout << std::endl;
	return;
}

void task8()
{
	std::string s;
	int m = 0, n = 0;
	std::cout << "Enter word, m and n (delimited with spaces): ";
	std::cin >> s >> m >> n;
	// s = s.substr(m-1, n-m+1);
	/*std::string r;
	m--, n--;
	for (int i = m; i < n; i++)
		r += s[i];
	std::cout << "Result: " << r << std::endl;*/
	char* r = new char[n-m+1+1];
	m--, n--;
	for (int i = m; i <= n; i++)
		r[i-m] = s[i];
	r[n-m+1] = '\0';
	std::cout << "Result: " << r << std::endl;
	delete[] r;
	return;
}

void task9()
{
	std::string s;
	std::cout << "Enter word: ";
	std::cin >> s;
	std::cout << "Result: " << std::string(s.size(), '*') << s << std::string(s.size(), '*') << std::endl;
	return;
}

void task10()
{
	std::string s;
	std::cout << "Enter sentence: ";
	std::cin.ignore();
	std::getline(std::cin, s);
	int ac = 0, gc = 0;
	for (auto i : s)
	{
		ac += (i == 'a');
		gc += (i != ' ');
	}
	ac *= 100;
	std::cout << "Result: " << (double(ac) / double(gc)) << "% (relatively to other non-space symbols)" << std::endl;
	return;
}

void task11()
{
	std::string cs = "Can you can a can as a canner can can a can?", s;
	std::cout << "Enter newWord: ";
	std::cin.ignore();
	std::getline(std::cin, s);
	int p = cs.find("can");
	auto isletter = [](char c) -> bool
	{
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	};
	int offset = 0;
	while (p != std::string::npos)
	{
		if (p != 0 && p != (cs.size() - 1))
		{
			if (!isletter(cs[p - 1]) && !isletter(cs[p + 3]))
				cs.replace(p, 3, s);
			else
				offset = p + 1;
		}
		else if (p == 0)
		{
			if (!isletter(cs[p + 3]))
				cs.replace(p, 3, s);
			else
				offset = p + 1;
		}
		else
		{
			if (!isletter(cs[p - 1]))
				cs.replace(p, 3, s);
			else
				offset = p + 1;
		}
		p = cs.find("can", offset);
	}
	std::cout << "Result: " << cs << std::endl;
	return;
}

int main()
{
	std::cout << "Enter number of task: ";
	int nt;
	std::cin >> nt;
	switch (nt)
	{
		case 1:
		{
			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		case 4:
		{
			task4();
			break;
		}
		case 5:
		{
			task5();
			break;
		}
		case 6:
		{
			task6();
			break;
		}
		case 7:
		{
			task7();
			break;
		}
		case 8:
		{
			task8();
			break;
		}
		case 9:
		{
			task9();
			break;
		}
		case 10:
		{
			task10();
			break;
		}
		case 11:
		{
			task11();
			break;
		}
	}
	return 0;
}

template <class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_real_distribution<> dist(min, max);

	auto lambda = [&e2, &dist]() -> T
	{
		return dist(e2);
	};

	std::vector<T> result(num);
	std::generate_n(result.begin(), num, lambda);
	return result;
}