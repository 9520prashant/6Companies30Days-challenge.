// 1054. Distant Barcodes

vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
  unordered_map<int, int> m;
  set<pair<int, int>> s;
  for (auto n : b) ++m[n];
  for (auto it = begin(m); it != end(m); ++it) s.insert({ it->second, it->first });
  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
      if (pos >= b.size()) pos = 1;
      b[pos] = it->second;
    }
  }
  return b;
}