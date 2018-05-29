
# Word_Counterr

## Description
Counts Words, Shows in which line they're

# Sample output
### O0  
![alt text](https://i.imgur.com/UFrgu8v.png)


### Cool
Uses Both set and map<string,struct>

```c++
struct data{
    int count{};
    std::set<int> lines{};
};
std::map<std::string, data> WordCounts;
```

### Changelog v1.0
#### Added
 - uses map 
 - uses set
### Changes
- fixed bug where it counter capitalized words differently

### Changelog first
#### Added
 - barely working counter
