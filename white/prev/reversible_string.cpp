class ReversibleString {
  public:
    ReversibleString() {}
    ReversibleString(const string& str) {
      s = str;
    }
    
    string ToString() const {
      return s;
    }
    
    void Reverse() {
      string new_str;
      int size = s.length();
      for (int i = size-1; i > -1; --i) {
  	new_str += s[i];
      }
      s = new_str;
    }

  private:
    string s;
};

