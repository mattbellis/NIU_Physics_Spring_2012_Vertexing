//=============================================================================
// test_doca.cpp
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-22
// Description: Test case calculating the distance of closest approach of lines
//                stored as endpoints in a csv file
//=============================================================================

#include "line.h"
#include "doca.h"

#include <stdio.h>
#include <stdlib.h>

#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// TODO<Ken LaBuda>: prompt user for filename
string CSV_FILENAME = "lines.csv";

int main()
{
  // container to store a list of lines to be processed
  deque<Line> lines;
  // buffer that will contain the endpoints of each line as its read in
  double endpoint_buffer[6];
  
  /////////////////////////////////////////////////////////////////////////////
  // Parse the csv line by line and extract endpoint info for each line
  cout << endl << "[info] opening file: " << CSV_FILENAME << endl;
  ifstream input_file(CSV_FILENAME.c_str());
  cout << "[info] reading file" << endl;
  int csv_row_number = 0;
  // buffer that will hold one line of the csv as a string
  string csv_row;
  while (getline(input_file, csv_row))
  {
    csv_row_number++;
    // create a stream that will sllow us to chop up a row with getline()
    istringstream csv_row_stream(csv_row, istringstream::in);
    string csv_item;
    int item_number = 0;
    // get one component of an endpoint each iteration of the loop
    while (getline(csv_row_stream,csv_item, ','))
    {
      // convert csv item to a double and store in buffer
      endpoint_buffer[item_number] = strtod(csv_item.c_str(),NULL);
      item_number++;
    }
    // unless there are 6 items in a row (3 for each endpoint) discard the row
    if (item_number != 6) {
      cout << "[warning] Invalid Row Found" << endl;
    } else {
      // create a Line object from endpoints in buffer and push onto the deque
      lines.push_back (Line(endpoint_buffer[0],endpoint_buffer[1],endpoint_buffer[2],
                            endpoint_buffer[3],endpoint_buffer[4],endpoint_buffer[5]));
    }
  }
  cout << "[info] Found " << csv_row_number << " rows." << endl;
  cout << "[debug] deque contains " << (int) lines.size() << " items." << endl;
  cout << "[info] Computing DOCA's" << endl;
  
  /////////////////////////////////////////////////////////////////////////////
  // iterate through deck finding doca from each line to each other line.
  //   e.g. for 4 lines the comparisons done will be:
  //   1-2, 1-3, 1-4, 2-3, 2-4, 3-4
  //   A line will not be compared to itself
  //   Line numbering starts at 1
  deque<Line>::iterator line_iterator_i;
  deque<Line>::iterator line_iterator_j;
  // line numbers used for labeling output
  int line_number_i = 1;
  int line_number_j = 1;
  
  line_iterator_i = lines.begin();
  while (line_iterator_i != lines.end())
  {
    line_iterator_j = line_iterator_i + 1;
    line_number_j = line_number_i + 1;
    while ( line_iterator_j != lines.end() )
    {
      cout << "Line " << line_number_i << " to line " << line_number_j << ": "
           << doca(*line_iterator_i, *line_iterator_j) << endl;
      line_iterator_j++;
      line_number_j++;
    }
    line_iterator_i++;
    line_number_i++;
  }
}