#! /usr/bin/python3
# highest.py
# input: json file with rows <score>: <json string>
# ex:  python3 highest.py score_recs.data 1

import sys
import json
import collections

if __name__ == "__main__":
    if len(sys.argv) < 3 :
        print("USAGE: python3 highest.py <data_file> <number_scores_to_show>")
        exit(1)
    input_file = sys.argv[1] 
    target_score_count = sys.argv[2]

    data_dict = {}
    with open (input_file) as f:
        for line in f.read().splitlines():
            score_val, json_val = line.split(':', 1)
            data_dict[score_val] = json_val

    data = list(collections.OrderedDict(sorted(data_dict.items())).items())
    # print(data)

    result_set = []
    try:
        for i in range(0, int(target_score_count)):
            json_data = json.loads(data[i][1])
            json_string = {"score" : data[i][0], "id" : json_data['id']}
            result_set.append(json_string)
    except:
        print(f"Invalid json format No JSON object could be decoded {data[i][1]}")
        exit(1)
    
    with open (f'{input_file}_output.json', 'w') as json_file:
        json.dump(result_set, json_file, indent=4, separators=(',',': '))

    exit(0) 