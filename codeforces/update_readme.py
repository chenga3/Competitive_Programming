import os
import re
import requests

# Get problem data from Codeforces API
r = requests.get('https://codeforces.com/api/problemset.problems')
problems_request = r.json()
problems = problems_request['result']['problems']

basedir = os.path.dirname(os.path.realpath(__file__))

with open('README.md', 'w') as f:
    # Write header
    f.write('# Problem List:\n')
    # For each cpp file, find the corresponding problem from the API response. Print out details about the problem.
    for file in os.listdir(basedir):
        filename = os.fsdecode(file)
        if filename.endswith('.cpp'):
            problem_id = filename.split('_')[0]
            match = re.search('[A-Z]', problem_id)
            contest_id = int(problem_id[:match.start()])
            index = problem_id[match.start():]
            for problem in problems:
                if problem['contestId'] == contest_id and problem['index'] == index:
                    problem_string = '- ' + \
                        str(problem['contestId']) + problem['index'] + \
                        ' ' + problem['name'] + '\n'
                    f.write(problem_string)
