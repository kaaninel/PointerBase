struct StringSerializer
{
    string& value;
    StringSerializer(string const& v):value(const_cast<string&>(v)){}
    friend ostream& operator<<(ostream& stream, StringSerializer const& data)
    {
        stream << data.value.size() << ':' << data.value;
    }
    friend istream& operator>>(istream& stream, StringSerializer const& data)
    {
        size_t size;
        char mark(' ');
        stream >> size >> mark;
        if (!stream || mark != ':')
        {    
          stream.setstate(ios::badbit);
          return stream;
        }
        data.value.resize(size);
        stream.read(&data.value[0], size);
    }
};

