#include "Map.h"

int Map::hash(string key)
{
  int sum = 0;

  for(int i=0;i < (int)key.length();i++)
    sum+=key[i];

  return sum;
}

Map::Map()
{
  for(int i=0;i<999999;i++)
  {
    array.push_back(new list< pair<string,int>* >);
  }
}

void Map::put(string key, int value)
{
  list< pair<string, int>* > * v =  array[hash(key)];
  v->push_back(new pair<string, int>(key, value));
}

int Map::get(string key)
{
  list< pair<string, int>* > * v =  array[hash(key)];
  for(list< pair<string, int>* >::iterator i = v->begin(); i != v->end(); i++)
  {
    pair<string, int>* current_pair = *i;
    if(current_pair->first == key)
      return current_pair->second;
  }

  return -1;
}

bool Map::exists(string key)
{
  return get(key) != -1;
}

void Map::remove(string key)
{
  list< pair<string, int>* > * v = array[hash(key)];
  for(list< pair<string, int>* >::iterator i = v->begin(); i != v->end(); i++){
    if((*i)->first == key){ v->erase(i); return; }
  }
}
